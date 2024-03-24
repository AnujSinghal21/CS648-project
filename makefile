# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -O3 -flto -march=native

# Source files
SRCS = analysis1.cpp algo1.cpp util.cpp

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = analysis1 analysis2

# Default target
all: $(TARGET)

# Compile source files into object files
util.o: util.cpp util.hpp
	$(CC) $(CFLAGS) -c util.cpp -o util.o
algo1.o: algo1.cpp algo1.hpp util.hpp
	$(CC) $(CFLAGS) -c algo1.cpp -o algo1.o
algo2.o: algo2.cpp algo2.hpp util.hpp
	$(CC) $(CFLAGS) -c algo2.cpp -o algo2.o
analysis1.o: analysis1.cpp algo1.hpp util.hpp
	$(CC) $(CFLAGS) -c analysis1.cpp -o analysis1.o
analysis1: analysis1.o algo1.o util.o
	$(CC) $(CFLAGS) analysis1.o algo1.o util.o -o analysis1
analysis2.o: analysis2.cpp algo2.hpp util.hpp
	$(CC) $(CFLAGS) -c analysis2.cpp -o analysis2.o
analysis2: analysis2.o algo2.o util.o
	$(CC) $(CFLAGS) analysis2.o algo2.o util.o -o analysis2
# Clean up object files and the target executable
clean:
	rm -f $(OBJS) $(TARGET)
