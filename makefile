CC = gcc
C_FLAGS = -Wall -pthread -g
TARGET = main

all: 
	make clean; make build;
clean:
	rm main b_buffer.o main.o

build: main.o b_buffer.o
	$(CC) $(C_FLAGS) -o $(TARGET) main.o b_buffer.o

b_buffer.o: b_buffer.c b_buffer.h
	$(CC) $(C_FLAGS) -c b_buffer.c

main.o: main.c
	$(CC) $(C_FLAGS) -c main.c