CFLAGS = -O2 -Wall -Wextra -Wfloat-equal -pedantic -ansi -lm
INCS =  test.txt
TARGET = 	1.2
SOURCES =  huffman.c $(TARGET).c
CC = gcc


all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

run: all
	$(TARGET) 