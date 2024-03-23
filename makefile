# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -O3 -flto -march=native

# Source files
SRCS = analysis1.c algo1.c util.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = analysis1

# Default target
all: $(TARGET)

# Compile source files into object files
util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c -o util.o
algo1.o: algo1.c algo1.h util.h
	$(CC) $(CFLAGS) -c algo1.c -o algo1.o
analysis1.o: analysis1.c algo1.h util.h
	$(CC) $(CFLAGS) -c analysis1.c -o analysis1.o
analysis1: analysis1.o algo1.o util.o
	$(CC) $(CFLAGS) analysis1.o algo1.o util.o -o analysis1

# Clean up object files and the target executable
clean:
	rm -f $(OBJS) $(TARGET)
