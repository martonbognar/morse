test: main.c
	clang -g -std=c99 -Wall -Wextra -Wfloat-equal -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wformat=2 -Wunreachable-code -pedantic *.c -o main
