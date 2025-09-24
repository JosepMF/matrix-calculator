CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJS = main.o matrixlib.o meta_matrix.o
TARGET = project


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)


main.o: main.c matrixlib.h
	$(CC) $(CFLAGS) -c main.c

matrixlib.o: matrixlib.c matrixlib.h
	$(CC) $(CFLAGS) -c matrixlib.c

meta_matrix.o: meta_matrix.c meta_matrix.h
	$(CC) $(CFLAGS) -c meta_matrix.c

clean:
	rm -f *.o $(TARGET)