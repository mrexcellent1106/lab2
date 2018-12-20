Практическая работа №2

Интерпретатор обратной польской записи арифметического выражения

Инстркуция по сборке:
1. Открыть консоль в папке с исходными файлами;
2. Воспользоваться утилитой GNU Make:
# make -f makefile.txt all
или
# mingw32-make -f makefile.txt all
3. Исполняемый файл - inventor.exe.

Для очистки директории от скомпилированных файлов воспользуйтесь командой:
# make -f makefile.txt clean
или
# mingw32-make -f makefile.txt clean

Для запуска теста приложения воспользуйтесь командой:
# make -f makefile.txt test
или
# mingw32-make -f makefile.txt test

Как пользоваться:

./inventor <тут_пишем_польскую_запись>

Пример: ./inventor 5 3 +