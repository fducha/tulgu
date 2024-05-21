assume CS:code,DS:data
code segment
begin:
mov AX,data 
mov DS,AX 
mov AH, 09h 
mov DX, offset msg 
int 21h 

mov AX, 4C00h 
int 21h 
code ends 

data segment 
msg db "Hello world!$" 
data ends 

stk segment stack 
db 256 dup (?) 
stk ends 
end begin 