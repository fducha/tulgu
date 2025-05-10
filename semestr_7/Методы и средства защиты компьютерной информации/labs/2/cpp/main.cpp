#include <stdio.h>
#include <iostream>
#include <cmath>
#include <termios.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include "des.cpp"

using namespace std;
using std::ofstream;
using std::ifstream;
using std::exit;

void demo_DES_crypto() {
    des_ctx dc;
    int i;
    unsigned long data[10];
    unsigned char *cp,key[8] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};
    unsigned char x[8] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xe7};
    cp = x;
    des_key(&dc,key);
    des_enc(&dc,cp,1);
    printf("Enc(0..7,0..7) = ");
    for(i=0;i<8;i++) printf("%02x ", ((unsigned int) cp[i])&0x00ff);
    printf("\n");
    des_dec(&dc,cp,1);
    printf("Dec(above,0..7) = ");
    for(i=0;i<8;i++) printf("%02x ",((unsigned int)cp[i])&0x00ff);
    printf("\n");
    cp = (unsigned char *) data;
    for(i=0;i<10;i++)data[i]=i;
    des_enc(&dc,cp,5); /* Enc 5 blocks. */
    for(i=0;i<10;i+=2) printf("Block %01d = %08lx %08lx.\n", i/2,data[i],data[i+1]);
    des_dec(&dc,cp,1);
    des_dec(&dc,cp+8,4);
    for(i=0;i<10;i+=2) printf("Block %01d = %08lx %08lx.\n", i/2,data[i],data[i+1]);
}

string getPassword() {
    string password;
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  
    char ch;
    while ((ch = getchar()) != '\n') {
        if (ch == 127) {
        // Handle backspace
        if (!password.empty()) {
            std::cout << "\b \b";
            password.pop_back();
        }
        } else {
            password += ch;
            cout << '*';
        }
    }
    cout << '\n';
  
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return password;
}

unsigned long long my_hash_func(const string &p) {
    short n = p.size();
    if (n > 16) {
        n = 16;
        cout << "Only the first 16 characters will be used." << endl;
    }
    short q = 98;
    short g = 21;
    short m = n / 2;
    int lsum = 0;
    for (size_t i = 0; i < m; i++) {
        lsum += (int) p[i];
    }
    int rsum = 0;
    for (size_t i = m; i < n; i++) {
        rsum += (int) p[i];
    }

    /*
    example password - tulgu => ascii is 116, 117, 108, 103, 117
    left side - 2 chars, sum = 233
    right side - 3 chars, sum = 328
    233^5 = 686719856393
    328^5 = 3796375994368
    result = 98 * 686719856393 + 21 * 3796375994368 = 147022441808242
    */
    
    return q * powf64x(lsum, n) + g * powf64x(rsum, n);
}

unsigned long long get_my_hash_from_file() {
    ifstream in("pwd", ios::in);
    if (!in) return 777;
    unsigned long long hash;
    in >> hash;
    in.close();
    return hash;
}

void log_wrong_attempt() {
    ofstream out("my_logs.log", ios::app);
    if (!out) {
        cerr << "Log file is not opened" << endl;
        exit(1);
    }
    auto t = chrono::system_clock::now();
    std::time_t tt = chrono::system_clock::to_time_t(t);
    out << ctime(&tt);
    out.close();
}

bool set_password() {
    cout << "Enter new password: ";
    auto p1 = getPassword();
    cout << "Confirm password: ";
    auto p2 = getPassword();
    if (p1 != p2) {
        cout << "Passwords are different." << endl;
        return false;
    }
    ofstream out("pwd", ios::out);
    if (!out) {
        cerr << "Password file is not opened" << endl;
        return false;
    }
    out << my_hash_func(p1);
    out.close();
    return true;
}

int main() {
    if (get_my_hash_from_file() == 777) {
        while (!set_password()) {}        
    }
    short attempts = 3;
    cout << "Hello!! Enter password: ";
    while (attempts > 0) {
        string pswd = getPassword();
        auto right_hash = get_my_hash_from_file();
        if (my_hash_func(pswd) == right_hash) {
            cout << "Password is OK" << endl;
            demo_DES_crypto();
            return 0;
        } else {
            log_wrong_attempt();
            cout << "Password is wrong!! ";
            attempts--;
            if (attempts > 0) cout << "Enter password again: ";
        }
    }
    if (attempts == 0) {
        cout << "App is terminating ... " << endl;
    }
    return 0;
}