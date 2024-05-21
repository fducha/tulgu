 .386
 .model flat,stdcall
option casemap:none

includelib kernel32.lib

SetConsoleTitleA PROTO :DWORD
GetStdHandle PROTO     :DWORD
WriteConsoleA PROTO    :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExitProcess PROTO      :DWORD
Sleep PROTO            :DWORD


 .const
sWriteText  db 'Hello world!!!!!'

 .code
Main PROC
  LOCAL hStdout :DWORD

  push -11
  call GetStdHandle
  mov hStdout,EAX

  push 0
  push 0
  push 16d
  push offset sWriteText
  push hStdout
  call WriteConsoleA

  push 2000d
  call Sleep

  push 0
  call ExitProcess

Main ENDP

end Main