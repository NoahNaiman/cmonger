CC = gcc
CFLAGS = -c -Wall -Wpedantic
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = bin/cmonger

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f bin/*
	rm -f src/*.o
