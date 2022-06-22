CC = g++
SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
INCLUDES = -Iinclude -I../include
LIBS = -l../lib
CFLAGS = -lhorrific -Wall -Wextra -ggdb

EXE = bin/test

test:
    $(CC) -o $(EXE) $(SRC) $(INCLUDES) $(CFLAGS)

bindirs:
    mkdir bin/
