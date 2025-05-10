setlocal
gcc -E hello.c -o hello.i

gcc -S hello.c -o  hello.s

gcc -c hello.c -o hello.o

gcc hello.o -o  hello.exe
endlocal