@ECHO OFF
IF (%1)==() ECHO � ��������� ��ப� �� ����� ��ࠬ��� IF (%1)==() GOTO END

IF NOT EXIST %1.ASM ECHO ����୮� ��� 䠩��!
IF NOT EXIST %1.ASM GOTO END
ECHO ***************************************************************
ECHO ���⥬� �ணࠬ��஢���� Turbo Assembler Version 4.0
ECHO �ணࠬ���� - ��㤥�� ��. ��262521-� ��⥬�� �.�.
ECHO ***************************************************************
ECHO �࠭᫨����� 䠩� %1.ASM. ��������� 䠩� ���⨭�� %1.LST 
C:\TASM\TASM /L /T /ZI /N %1
IF ERRORLEVEL 1 ECHO �訡�� �࠭��樨!
IF ERRORLEVEL 1 GOTO END
CHOICE /C:YN /N /T 8 /D Y /M "������� ��ꥪ�� ����� (�� - Y, ��� - N):"
IF ERRORLEVEL 2 GOTO END
IF ERRORLEVEL 1 ECHO ��ன �⠯ �࠭��樨. ��������� 䠩� %1.OBJ
CHOICE /C:ecn /N /T 8 /D e /M "������� EXE-䠩� - E, COM-䠩� - C, �⪠� - N:"
IF ERRORLEVEL 3 GOTO END
IF ERRORLEVEL 2 GOTO ONE
IF ERRORLEVEL 1 GOTO TWO
:ONE
TLINK /T %1.OBJ
GOTO END
:TWO
TLINK %1.OBJ
:END
SHIFT
IF NOT "%1"=="" GOTO LOOP
ECHO ����� ࠡ��� ���������� 䠩��