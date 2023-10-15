@ECHO OFF
REM Командный файл автоматизации компиляции программы REM на языке Ассемблера. Используется драйвер ANSY.SYS CLS
REM Проверить наличие параметров в командной строке
IF (%1)==() ECHO Esc[31;1mВ командной строке не задан параметр!Esc[0m IF (%1)==() GOTO END
REM Проверка существования файлов
IF NOT EXIST %1.ASM ECHO Esc[31;1mНеверное имя файла!Esc[0m
IF NOT EXIST %1.ASM GOTO END
REM Задать цвет символов и фона для вывода заставки ECHO Esc[37;44m
ECHO ***************************************************************
ECHO Система программирования Turbo Assembler Version 4.0
ECHO Программист – студент гр. ИБ262521-ф Артемов А.Е.
ECHO ***************************************************************
REM Вернуться к нормальному изображению
ECHO Esc[0m
REM Запомнить координаты курсора
ECHO Esc[s
:LOOP
REM Восстановить координаты курсора
ECHO Esc[u
ECHO Транслируется файл %1.ASM. Создается файл листинга %1.LST TASM /L /T /ZI /N %1,NUL,%1
IF ERRORLEVEL 1 ECHO Esc[31;1mОшибка трансляции!Esc[0m
IF ERRORLEVEL 1 GOTO END
CHOICE /C:YN /N/T:N,8 Создать объектный модуль (Да – Y, Нет – N):
IF ERRORLEVEL 2 GOTO END
IF ERRORLEVEL 1 ECHO Второй этап трансляции. Создается файл %1.OBJ IF ERRORLEVEL 1 TASM %1,%1,NUL
CHOICE /C:ECN /N /T:N,8 Создать EXE-файл – E, COM-файл – C, отказ – N:
IF ERRORLEVEL 3 GOTO END
IF ERRORLEVEL 2 GOTO ONE
IF ERRORLEVEL 1 GOTO TWO
:ONE
TLINK /T %1.OBJ
GOTO END
:TWO
TLINK %1.OBJ
:END
REM Сдвинуть список параметров влево
SHIFT
REM Переход на метку LOOP, если параметры еще доступны
IF NOT "%1"=="" GOTO LOOP
ECHO Конец работы командного файла
