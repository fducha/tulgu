@ECHO OFF
IF (%1)==() ECHO � ��������� ��ப� �� ����� ��ࠬ��� IF (%1)==() GOTO END

IF NOT EXIST %1.ASM ECHO ����୮� ��� 䠩��!
IF NOT EXIST %1.ASM GOTO END
ECHO ***************************************************************
ECHO ���⥬� �ணࠬ��஢���� Macro Assembler Version 6.14.844
ECHO �ணࠬ���� - ��㤥�� ��. ��262521-� ��⥬�� �.�.
ECHO ***************************************************************
ECHO �࠭᫨����� 䠩� %1.ASM.
C:\masm32\bin\ml.exe /c /coff %1.ASM
IF ERRORLEVEL 1 ECHO �訡�� �࠭��樨!
IF ERRORLEVEL 1 GOTO END
CHOICE /C:YN /N /T 8 /D Y /M "������� ��ꥪ�� ����� (�� - Y, ��� - N):"
IF ERRORLEVEL 2 GOTO END
IF ERRORLEVEL 1 ECHO ��ன �⠯ �࠭��樨. ��������� 䠩� %1.OBJ
CHOICE /C:en /N /M "������� EXE-䠩� - E, �⪠� - N:"
IF ERRORLEVEL 2 GOTO END
IF ERRORLEVEL 1 GOTO ONE
:ONE
C:\masm32\bin\link /SUBSYSTEM:CONSOLE /LIBPATH:c:\masm32\lib %1.OBJ
GOTO END
:END
SHIFT
IF NOT "%1"=="" GOTO LOOP
ECHO ����� ࠡ��� ���������� 䠩��