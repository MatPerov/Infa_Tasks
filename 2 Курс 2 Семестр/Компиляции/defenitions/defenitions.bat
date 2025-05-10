
gcc -c main.c
gcc -c -DUPPERCASE alice.c
gcc -c bob.c
gcc alice.o bob.o main.o -o programm.exe
programm.exe