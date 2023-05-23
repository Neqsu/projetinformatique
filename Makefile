CC = gcc
EXEC = prog

all : $(EXEC)

prog : main.o functions.o game_board.o
	$(CC) -o $(EXEC) main.o functions.o game_board.o

main.o : main.c
	$(CC) -o main.o -c main.c

functions.o : functions.c
	$(CC) -o functions.o -c functions.c

game_board.o : game_board.c
	$(CC) -o game_board.o -c game_board.c
