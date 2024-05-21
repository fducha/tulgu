@ECHO OFF
IF (%1)==() ECHO В командной строке не задан параметр IF (%1)==() GOTO END

IF NOT EXIST %1.ASM ECHO Неверное имя файла!
IF NOT EXIST %1.ASM GOTO END
ECHO ***************************************************************
ECHO Система программирования Turbo Assembler Version 4.0
ECHO Программист - студент гр. ИБ262521-ф Артемов А.Е.
ECHO ***************************************************************
ECHO Транслируется файл %1.ASM. Создается файл листинга %1.LST 
C:\TASM\TASM /L /T /ZI /N %1
IF ERRORLEVEL 1 ECHO Ошибка трансляции!
IF ERRORLEVEL 1 GOTO END
CHOICE /C:YN /N /T 8 /D Y /M "Создать объектный модуль (Да - Y, Нет - N):"
IF ERRORLEVEL 2 GOTO END
IF ERRORLEVEL 1 ECHO Второй этап трансляции. Создается файл %1.OBJ
CHOICE /C:ecn /N /T 8 /D e /M "Создать EXE-файл - E, COM-файл - C, отказ - N:"
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
ECHO Конец работы командного файла