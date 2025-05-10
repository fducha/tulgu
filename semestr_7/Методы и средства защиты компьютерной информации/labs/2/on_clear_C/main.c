#include <stdio.h>
#include <string.h>

#define EN0     0          /* MODE == encrypt */
#define DE1     1          /* MODE == decrypt */

typedef struct {
    unsigned long ek[32];
    unsigned long dk[32];
} des_ctx;

extern void deskey (unsigned char *, short);
/*             hexkey[8]              MODE

*Sets the internal key register according to the hexadecimal
*key contained in the 8 bytes of hexkey, according to the DES,
*for encryption or decryption according to MODE.
*/

extern void usekey(unsigned long *);
/*               cookedkey[32]
*Loads the internal key register with the data in cookedkey.
*/

extern void cpkey(unsigned long *);
/*              cookedkey[32]
*Copies the contents of the internal key register into the storage
*located at &cookedkey[0].
*/

extern void des(unsigned char *, unsigned char *);
/*               from[8]        to[8]
*Encrypts/Descrypts (according to the key currently loaded in the
*internal key register) one block of eight bytes at address ‘from’
*into the block at address ‘to’. They can be the same.
*/

static void scrunch(unsigned char *, unsigned long *);
static void unscrun(unsigned long *, unsigned char *);
static void desfunc(unsigned long *, unsigned long *);
static void cookey(unsigned long *);

static unsigned long KnL[32] = { 0L };
static unsigned long KnR[32] = { 0L };
static unsigned long Kn3[32] = { 0L };
static unsigned char Df_Key[24] = {
    0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
    0xef,0xdc,0xba,0x98,0x76,0x54,0x32,0x10,
    0x89,0xab,0xcd,0xef,0x01,0x23,0x45,0x67 };

static unsigned short bytebit[8] = {0200, 0100, 040, 020, 010, 04, 02, 01 };

static unsigned long bigbyte[24] = {
    0x800000L, 0x400000L, 0x200000L, 0x100000L,
    0x80000L,  0x40000L,  0x20000L,  0x10000L,
    0x8000L,   0x4000L,   0x2000L,   0x1000L,
    0x800L,    0x400L,    0x200L,    0x100L,
    0x80L,     0x40L,     0x20L,     0x10L,
    0x8L,      0x4L,      0x2L,      0x1L };

/* Use the key schedule specified in the Standart (ANSI X3.92-1981).

*/ 
static unsigned char pc1[56] = {
    56, 48, 40, 32, 24, 16, 8, 0, 57, 49, 41, 33, 25, 17,
    9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35,
    62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21,
    13, 5, 60, 52, 44, 36, 28, 20, 12, 4, 27, 19, 11, 3};

static unsigned char totrot[16] = {
    1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28 };

static unsigned char pc2[48] = {
    13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 20, 9,
    22, 18, 11, 3, 25, 7, 15, 6, 26, 19, 12, 1,
    40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47,
    43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31 };

void deskey(unsigned char *key, short edf) {
    int i, j, l, m, n;

    unsigned char pc1m[56], pcr[56];
    unsigned long kn[32];

    for (j = 0; j < 56; j++ ) {
        l = pc1[j];
        m = l & 07;
        pc1[j] = (key[1 >> 3] & bytebit[m]) ? 1 : 0;
    }
    for (i = 0;  i < 16; i++ ) {
        if (edf == DE1) m = (15 - i) << 1; 
        else m = i << 1;
        n = m + 1;
        kn[m] = kn[n] = 0L;
        for (j = 0; j < 28; j++ ) {
            l = j + totrot[i];
            if (l < 28 ) pcr[j] = pc1m[l];
            else pcr[j] = pc1m[l - 28];
        }
        for (j = 28; j < 56; j++ ) {
            l = j + totrot[i];
            if (l < 56) pcr[j] = pc1m[l];
            else pcr[j] = pc1m[l - 28];
        }
        for( j = 0; j < 24; j++ ) {
            if (pcr[pc2[j]]) kn[m] |= bigbyte[j];
            if (pcr[pc2[j+24]]) kn[m] |= bigbyte[j];
        }
    }
    cookey(kn);
    return;
}

static void cookey(unsigned long *raw1) {
    unsigned long *cook, *raw0;
    unsigned long dough[32];
    int i;

    cook = dough;
    for ( i = 0; i < 16; i++, raw1++ ) {
        raw0     = raw1++;
        *cook    = (*raw0 & 0x00fc0000L) << 6;
        *cook   |= (*raw0 & 0x00000fc0L) << 10;
        *cook   |= (*raw1 & 0x00fc0000L) >> 10;
        *cook++ |= (*raw1 & 0x00000fc0L) >> 6;
        *cook    = (*raw0 & 0x0003f000L) << 12;
        *cook   |= (*raw0 & 0x0000003fL) << 16;
        *cook   |= (*raw1 & 0x0003f000L) >> 4;
        *cook++ |= (*raw1 & 0x0000003fL);
    }

    usekey (dough);
    return;
}

void cpkey(unsigned long *into) {
    unsigned long *from, *endp;
    from = KnL, endp = &KnL[32];
    while (from < endp) 
        *into++ = *from++;
    return;
}

void usekey(unsigned long *from) {
    unsigned long *to, *endp;

    to = KnL, endp = &KnL[32];
    while (to < endp) 
        *to++ = *from++;
    return;
}

void des(unsigned char *inblock, unsigned char *outblock) {
    unsigned long work[2];

    scrunch(inblock, work);
    desfunc(work, KnL);
    unscrun(work, outblock);
    return;
}

static void scrunch(unsigned char *outof, unsigned long *into) {
    *into = (*outof++ & 0xffL) << 24;
    *into |= (*outof++ & 0xffL) << 16;
    *into |= (*outof++ & 0xffL) << 8;
    *into++ |= (*outof++ & 0xffL);
    *into = (*outof++ & 0xffL) << 24;
    *into |= (*outof++ & 0xffL) << 16;
    *into |= (*outof++ & 0xffL) << 8;
    *into |= (*outof & 0xffL);
    return;
    // into[0] = ((unsigned long)outof[0] << 24) |
    //           ((unsigned long)outof[1] << 16) |
    //           ((unsigned long)outof[2] << 8)  |
    //           ((unsigned long)outof[3]);

    // into[1] = ((unsigned long)outof[4] << 24) |
    //           ((unsigned long)outof[5] << 16) |
    //           ((unsigned long)outof[6] << 8)  |
    //           ((unsigned long)outof[7]);
}

static void unscrun(unsigned long *outof, unsigned char *into) {
    *into++ = (*outof >> 24) & 0xffL;
    *into++ = (*outof >> 16) & 0xffL;
    *into++ = (*outof >> 8) & 0xffL;
    *into++ = *outof++ & 0xffL;
    *into++ = (*outof >> 24) & 0xffL;
    *into++ = (*outof >> 16) & 0xffL;
    *into++ = (*outof >> 8) & 0xffL;
    *into = *outof & 0xffL;
    return;
    // into[0] = (outof[0] >> 24) & 0xff;
    // into[1] = (outof[0] >> 16) & 0xff;
    // into[2] = (outof[0] >> 8)  & 0xff;
    // into[3] = outof[0] & 0xff;

    // into[4] = (outof[1] >> 24) & 0xff;
    // into[5] = (outof[1] >> 16) & 0xff;
    // into[6] = (outof[1] >> 8)  & 0xff;
    // into[7] = outof[1] & 0xff;    
}

// static unsigned char SP1[64]={
//     14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
// 	0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
// 	4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
// 	15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};

// static unsigned char SP2[64]={
//     15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
// 	3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
// 	0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
// 	13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};

// static unsigned char SP3[64]={
//     10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
// 	13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
// 	13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
// 	1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};

// static unsigned char SP4[64]={
//     7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
// 	13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
// 	10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
// 	3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};

// static unsigned char SP5[64]={
//     2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
// 	14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
// 	4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
// 	11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};

// static unsigned char SP6[64]={
//     12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
// 	10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
// 	9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
// 	4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};

// static unsigned char SP7[64]={
//     4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
// 	13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
// 	1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
// 	6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};

// static unsigned char SP8[64]={
//     13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
// 	1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
// 	7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
// 	2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

static unsigned long SP1[64]={
    0x01010400L, 0x00000000L, 0x00010000L, 0x01010404L,
    0x01010004L, 0x00010404L, 0x00000004L, 0x00010000L,
    0x00000400L, 0x01010400L, 0x01010404L, 0x00000400L,
    0x01000404L, 0x01010004L, 0x01000000L, 0x00000004L,
    0x00000404L, 0x01000400L, 0x01000400L, 0x00010400L,
    0x00010400L, 0x01010000L, 0x01010000L, 0x01000404L,
    0x00010004L, 0x01000004L, 0x01000004L, 0x00010004L,
    0x00000000L, 0x00000404L, 0x00010404L, 0x01000000L,
    0x00010000L, 0x01010404L, 0x00000004L, 0x01010000L,
    0x01010400L, 0x01000000L, 0x01000000L, 0x00000400L,
    0x01010004L, 0x00010000L, 0x00010400L, 0x01000004L,
    0x00000400L, 0x00000004L, 0x01000404L, 0x00010404L,
    0x01010404L, 0x00010004L, 0x01010000L, 0x01000404L,
    0x01000004L, 0x00000404L, 0x00010404L, 0x01010400L,
    0x00000404L, 0x01000400L, 0x01000400L, 0x00000000L,
    0x00010004L, 0x00010400L, 0x00000000L, 0x01010004L};

static unsigned long SP2[64]={
    0x80108020L, 0x80008000L, 0x00008000L, 0x00108020L,
    0x00100000L, 0x00000020L, 0x80100020L, 0x80008020L,
    0x80000020L, 0x80108020L, 0x80108000L, 0x80000000L,
    0x80008000L, 0x00100000L, 0x00000020L, 0x80100020L,
    0x00108000L, 0x00100020L, 0x80008020L, 0x00000000L,
    0x80000000L, 0x00008000L, 0x00108020L, 0x80100000L,
    0x00100020L, 0x80000020L, 0x00000000L, 0x00108000L,
    0x00008020L, 0x80108000L, 0x80100000L, 0x00008020L,
    0x00000000L, 0x00108020L, 0x80100020L, 0x00100000L,
    0x80008020L, 0x80100000L, 0x80108000L, 0x00008000L,
    0x80100000L, 0x80008000L, 0x00000020L, 0x80108020L,
    0x00108020L, 0x00000020L, 0x00008000L, 0x80000000L,
    0x00008020L, 0x80108000L, 0x00100000L, 0x80000020L,
    0x00100020L, 0x80008020L, 0x80000020L, 0x00100020L,
    0x00108000L, 0x00000000L, 0x80008000L, 0x00008020L,
    0x80000000L, 0x80100020L, 0x80108020L, 0x00108000L};

static unsigned long SP3[64]={
    0x00000208L, 0x08020200L, 0x00000000L, 0x08020008L,
    0x08000200L, 0x00000000L, 0x00020208L, 0x08000200L,
    0x00020008L, 0x08000008L, 0x08000008L, 0x00020000L,
    0x08020208L, 0x00020008L, 0x08020000L, 0x00000208L,
    0x08000000L, 0x00000008L, 0x08020200L, 0x00000200L,
    0x00020200L, 0x08020000L, 0x08020008L, 0x00020208L,
    0x08000208L, 0x00020200L, 0x00020000L, 0x08000208L,
    0x00000008L, 0x08020208L, 0x00000200L, 0x08000000L,
    0x08020200L, 0x08000000L, 0x00020008L, 0x00000208L,
    0x00020000L, 0x08020200L, 0x08000200L, 0x00000000L,
    0x00000200L, 0x00020008L, 0x08020208L, 0x08000200L,
    0x08000008L, 0x00000200L, 0x00000000L, 0x08020008L,
    0x08000208L, 0x00020000L, 0x08000000L, 0x08020208L,
    0x00000008L, 0x00020208L, 0x00020200L, 0x08000008L,
    0x08020000L, 0x08000208L, 0x00000208L, 0x08020000L,
    0x00020208L, 0x00000008L, 0x08020008L, 0x00020200L};

static unsigned long SP4[64]={
    0x00802001L, 0x00002081L, 0x00002081L, 0x00000080L,
    0x00802080L, 0x00800081L, 0x00800001L, 0x00002001L,
    0x00000000L, 0x00802000L, 0x00802000L, 0x00802081L,
    0x00000081L, 0x00000000L, 0x00800080L, 0x00800001L,
    0x00000001L, 0x00002000L, 0x00800000L, 0x00802001L,
    0x00000080L, 0x00800000L, 0x00002001L, 0x00002080L,
    0x00800081L, 0x00000001L, 0x00002080L, 0x00800080L,
    0x00002000L, 0x00802080L, 0x00802081L, 0x00000081L,
    0x00800080L, 0x00800001L, 0x00802000L, 0x00802081L,
    0x00000081L, 0x00000000L, 0x00000000L, 0x00802000L,
    0x00002080L, 0x00800080L, 0x00800081L, 0x00000001L,
    0x00802001L, 0x00002081L, 0x00002081L, 0x00000080L,
    0x00802081L, 0x00000081L, 0x00000001L, 0x00002000L,
    0x00800001L, 0x00002001L, 0x00802080L, 0x00800081L,
    0x00002001L, 0x00002080L, 0x00800000L, 0x00802001L,
    0x00000080L, 0x00800000L, 0x00002000L, 0x00802080L};

static unsigned long SP5[64]={
    0x00000100L, 0x02080100L, 0x02080000L, 0x42000100L,
    0x00080000L, 0x00000100L, 0x40000000L, 0x02080000L,
    0x40080100L, 0x00080000L, 0x02000100L, 0x40080100L,
    0x42000100L, 0x42080000L, 0x00080100L, 0x40000000L,
    0x02000000L, 0x40080000L, 0x40080000L, 0x00000000L,
    0x40000100L, 0x42080100L, 0x42080100L, 0x02000100L,
    0x42080000L, 0x40000100L, 0x00000000L, 0x42000000L,
    0x02080100L, 0x02000000L, 0x42000000L, 0x00080100L,
    0x00080000L, 0x42000100L, 0x00000100L, 0x02000000L,
    0x40000000L, 0x02080000L, 0x42000100L, 0x40080100L,
    0x02000100L, 0x40000000L, 0x42080000L, 0x02080100L,
    0x40080100L, 0x00000100L, 0x02000000L, 0x42080000L,
    0x42080100L, 0x00080100L, 0x42000000L, 0x42080100L,
    0x02080000L, 0x00000000L, 0x40080000L, 0x42000000L,
    0x00080100L, 0x02000100L, 0x40000100L, 0x00080000L,
    0x00000000L, 0x40080000L, 0x02080100L, 0x40000100L};

static unsigned long SP6[64]={
    0x20000010L, 0x20400000L, 0x00004000L, 0x20404010L,
    0x20400000L, 0x00000010L, 0x20404010L, 0x00400000L,
    0x20004000L, 0x00404010L, 0x00400000L, 0x20000010L,
    0x00400010L, 0x20004000L, 0x20000000L, 0x00004010L,
    0x00000000L, 0x00400010L, 0x20004010L, 0x00004000L,
    0x00404000L, 0x20004010L, 0x00000010L, 0x20400010L,
    0x20400010L, 0x00000000L, 0x00404010L, 0x20404000L,
    0x00004010L, 0x00404000L, 0x20404000L, 0x20000000L,
    0x20004000L, 0x00000010L, 0x20400010L, 0x00404000L,
    0x20404010L, 0x00400000L, 0x00004010L, 0x20000010L,
    0x00400000L, 0x20004000L, 0x20000000L, 0x00004010L,
    0x20000010L, 0x20404010L, 0x00404000L, 0x20400000L,
    0x00404010L, 0x20404000L, 0x00000000L, 0x20400010L,
    0x00000010L, 0x00004000L, 0x20400000L, 0x00404010L,
    0x00004000L, 0x00400010L, 0x20004010L, 0x00000000L,
    0x20404000L, 0x20000000L, 0x00400010L, 0x20004010L};

static unsigned long SP7[64]={
    0x00200000L, 0x04200002L, 0x04000802L, 0x00000000L,
    0x00000800L, 0x04000802L, 0x00200802L, 0x04200800L,
    0x04200802L, 0x00200000L, 0x00000000L, 0x04000002L,
    0x00000002L, 0x04000000L, 0x04200002L, 0x00000802L,
    0x04000800L, 0x00200802L, 0x00200002L, 0x04000800L,
    0x04000002L, 0x04200000L, 0x04200800L, 0x00200002L,
    0x04200000L, 0x00000800L, 0x00000802L, 0x04200802L,
    0x00200800L, 0x00000002L, 0x04000000L, 0x00200800L,
    0x04000000L, 0x00200800L, 0x00200000L, 0x04000802L,
    0x04000802L, 0x04200002L, 0x04200002L, 0x00000002L,
    0x00200002L, 0x04000000L, 0x04000800L, 0x00200000L,
    0x04200800L, 0x00000802L, 0x00200802L, 0x04200800L,
    0x00000802L, 0x04000002L, 0x04200802L, 0x04200000L,
    0x00200800L, 0x00000000L, 0x00000002L, 0x04200802L,
    0x00000000L, 0x00200802L, 0x04200000L, 0x00000800L,
    0x04000002L, 0x04000800L, 0x00000800L, 0x00200002L};

static unsigned long SP8[64]={
    0x10001040L, 0x00001000L, 0x00040000L, 0x10041040L,
    0x10000000L, 0x10001040L, 0x00000040L, 0x10000000L,
    0x00040040L, 0x10040000L, 0x10041040L, 0x00041000L,
    0x10041000L, 0x00041040L, 0x00001000L, 0x00000040L,
    0x10040000L, 0x10000040L, 0x10001000L, 0x00001040L,
    0x00041000L, 0x00040040L, 0x10040040L, 0x10041000L,
    0x00001040L, 0x00000000L, 0x00000000L, 0x10040040L,
    0x10000040L, 0x10001000L, 0x00041040L, 0x00040000L,
    0x00041040L, 0x00040000L, 0x10041000L, 0x00001000L,
    0x00000040L, 0x10040040L, 0x00001000L, 0x00041040L,
    0x10001000L, 0x00000040L, 0x10000040L, 0x10040000L,
    0x10040040L, 0x10000000L, 0x00040000L, 0x10001040L,
    0x00000000L, 0x10041040L, 0x00040040L, 0x10000040L,
    0x10040000L, 0x10001000L, 0x10001040L, 0x00000000L,
    0x10041040L, 0x00041000L, 0x00041000L, 0x00001040L,
    0x00001040L, 0x00040040L, 0x10000000L, 0x10041000L};

static void desfunc(unsigned long *block, unsigned long *keys) {
    unsigned long fval, work, right, left;
    int round;

    left = block[0];
    right = block[1];

    // Начальная перестановка
    work = ((left >> 4) ^ right) & 0x0f0f0f0fL;
    right ^= work;
    left ^= (work << 4);
    work = ((work >> 16) ^ right) & 0x0000ffffL;
    right ^= work;
    left ^= (work << 16);
    work = ((left >> 2) ^ left) & 0x33333333L;
    left ^= work;
    right ^= (work << 2);
    work = ((right >> 8) ^ left) & 0x00ff00ffL;
    left ^= work;
    right ^= (work << 8);
    right = ((right << 1) | ((right >> 31) & 1L)) & 0xffffffffL;
    work = (left ^ right) & 0xaaaaaaaaL;
    left ^= work;
    right ^= work;
    left = ((left << 1) | ((left >> 31) & 1L)) & 0xffffffffL;

    // 16 раундов DES
    for (round = 0; round < 8; round++) {
        work = (right << 28) | (right >> 4);
        work ^= *keys++;
        fval = SP7[work & 0x3fL];
        fval |= SP5[(work >> 8) & 0x3fL];
        fval |= SP3[(work >> 16) & 0x3fL];
        fval |= SP1[(work >> 24) & 0x3fL];
        work = right ^ *keys++;
        fval |= SP8[work & 0x3fL];
        fval |= SP6[(work >> 8) & 0x3fL];
        fval |= SP4[(work >> 16) & 0x3fL];
        fval |= SP2[(work >> 24) & 0x3fL];
        left ^= fval;

        work = (left << 28) | (left >> 4);
        work ^= *keys++;
        fval = SP7[work & 0x3fL];
        fval |= SP5[(work >> 8) & 0x3fL];
        fval |= SP3[(work >> 16) & 0x3fL];
        fval |= SP1[(work >> 24) & 0x3fL];
        work ^= left ^ *keys++;
        fval |= SP8[work & 0x3fL];
        fval |= SP6[(work >> 8) & 0x3fL];
        fval |= SP4[(work >> 16) & 0x3fL];
        fval |= SP2[(work >> 24) & 0x3fL];
        right ^= fval;
    }

    // Финальная перестановка
    right = (right << 31) | (right >> 1);
    work = (left ^ right) & 0xaaaaaaaaL;
    left ^= work;
    right ^= work;
    left = (left << 31) | (left >> 1);
    work = ((left >> 8) ^ right) & 0x00ff00ffL;
    right ^= work;
    left ^= (work << 8);
    work = ((left >> 2) ^ right) & 0x33333333L;
    right ^= work;
    left ^= (work << 2);
    work = ((right >> 16) ^ left) & 0x0000ffffL;
    left ^= work;
    right ^= (work << 16);
    work = ((right >> 4) ^ left) & 0x0f0f0f0fL;
    left ^= work;
    right ^= (work << 4);

    *block++ = right;
*block = left;
return;
}

void des_key(des_ctx *dc, unsigned char *key){
    deskey(key,EN0);
    cpkey(dc->ek);
    deskey(key,DE1);
    cpkey(dc->dk);
}

/* Encript several bloks in ECB mode. Caller is responsible for short blocks. */
void des_enc(des_ctx *dc, unsigned char *data, int blocks) {
    if (!data || blocks <= 0) {
        printf("Ошибка 1\n");
        return;
    }

    unsigned long work[2];
    int i;
    unsigned char *cp;

    cp = data;
    for (i = 0; i < blocks; i++) {
        if (cp + 8 > data + blocks * 8) {
            printf("Ошибка 2\n");
            return;
        }
        scrunch(cp, work);
        desfunc(work, dc->ek);
        unscrun(work, cp);
        cp += 8;
    }
}

void des_dec(des_ctx *dc, unsigned char *data, int blocks) {
    unsigned long work[2];
    int i;
    unsigned char *cp;

    cp = data;
    for(i=0;i<blocks;i++) {
        scrunch(cp,work);
        desfunc(work,dc->dk);
        unscrun(work,cp);
        cp+=8;
    }
}

void main(){
    // des_ctx dc;
    // int i;
    // unsigned long data[10];
    // char *cp,key[8] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};
    // // char x[8] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xe7};
    // char x[8] = "papamama";

    // cp = x;
    // for(i=0;i<8;i++) printf("%02x ", ((unsigned int) cp[i])&0x00ff);
    // printf("\n");
    // des_key(&dc,key);
    // des_enc(&dc,cp,1);
    // printf("Enc(0..7,0..7) = ");
    // for(i=0;i<8;i++) printf("%02x ", ((unsigned int) cp[i])&0x00ff);
    // printf("\n");
    // des_dec(&dc,cp,1);

    // printf("Dec(above,0..7) = ");
    // for (i=0;i<8;i++) printf("%02x ", ((unsigned int) cp[i])&0x00ff);
    // printf("\n");

    // cp = (char *) data;
    // for(i=0;i<10;i++) data[i]=i;

    // des_enc(&dc,cp,5); /* Enc 5 blocks. */
    // for(i=0;i<10;i+=2) printf("Block %01d = %08lx %08lx.\n", i/2, data[i], data[i+1]);

    // des_dec(&dc,cp,1);
    // // des_dec(&dc,cp+8,4);
    // for(i=0;i<10;i+=2) printf("Block %01d = %08lx %08lx.\n", i/2, data[i], data[i+1]);

/* Validation sets:
*
* Single-length key, single- length plaintext –
* Key    : 0123 4567 89ab cdef
* Plain : 0123 4567 89ab cde7
* Cipher : c957 4425 6a5e d31d
*
*****************************************************************/

    des_ctx dc;
    unsigned char key[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    unsigned char data[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xe7};

    printf("Data:\n");
    for (int i = 0; i < 8; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");

    // Инициализация контекста DES
    des_key(&dc, key);

    // Шифрование данных (2 блока по 8 байт)
    des_enc(&dc, data, 1);

    // Вывод зашифрованных данных
    printf("Encrypted data:\n");
    for (int i = 0; i < 8; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");

    des_dec(&dc, data, 1);

    printf("Decrypted data:\n");
    for (int i = 0; i < 8; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");

    return 0;
}