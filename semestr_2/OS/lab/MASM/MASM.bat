@ECHO OFF
IF (%1)==() ECHO В командной строке не задан параметр IF (%1)==() GOTO END

IF NOT EXIST %1.ASM ECHO Неверное имя файла!
IF NOT EXIST %1.ASM GOTO END
ECHO ***************************************************************
ECHO Система программирования Macro Assembler Version 6.14.844
ECHO Программист - студент гр. ИБ262521-ф Артемов А.Е.
ECHO ***************************************************************
ECHO Транслируется файл %1.ASM.
C:\masm32\bin\ml.exe /c /coff %1.ASM
IF ERRORLEVEL 1 ECHO Ошибка трансляции!
IF ERRORLEVEL 1 GOTO END
CHOICE /C:YN /N /T 8 /D Y /M "Создать объектный модуль (Да - Y, Нет - N):"
IF ERRORLEVEL 2 GOTO END
IF ERRORLEVEL 1 ECHO Второй этап трансляции. Создается файл %1.OBJ
CHOICE /C:en /N /M "Создать EXE-файл - E, отказ - N:"
IF ERRORLEVEL 2 GOTO END
IF ERRORLEVEL 1 GOTO ONE
:ONE
C:\masm32\bin\link /SUBSYSTEM:CONSOLE /LIBPATH:c:\masm32\lib %1.OBJ
GOTO END
:END
SHIFT
IF NOT "%1"=="" GOTO LOOP
ECHO Конец работы командного файла