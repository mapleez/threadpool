#!/bin/bash

gcc -c ../src/testmod.c -o ../src/testmod.o -g
gcc -I../src -c ./test_testmod.c -g
gcc -L/usr/local/lib -lcunit -I../src  -o test_testmod test_testmod.o ../src/testmod.o -g
