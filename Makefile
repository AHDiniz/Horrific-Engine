ifeq ($(OS), Windows_NT)
CC = g++
CFLAGS = -Wall -Wextra -ggdb -pedantic -lraylib -lopengl32 -lgdi32 -lwinmm -lm -static -std=c++17
LIBS = -Lvendor/raylib/lib/windows
else
CC = g++
CFLAGS = -Wall -Wextra -ggdb -pedantic -lraylib -lGL -lm -lpthread -ldl -lX11 -std=c++17
LIBS = -Lvendor/raylib/lib/linux
endif

EXE = bin/horrific

INCLUDE = -Iinclude/ -Ivendor/raylib/include/ -Ivendor/json
SOURCE = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard include/*.hpp) $(wildcard include/**/*.hpp)

game: $(wildcard src/*.cpp) $(wildcard include/*.hpp) $(wildcard src/**/*.cpp) $(wildcard include/**/*.hpp)
	$(CC) $(LIBS) $(INCLUDE) -o $(EXE) $(SOURCE) $(CFLAGS)

bindirs:
	mkdir bin/ && mkdir lib/

run:
	./$(EXE)

pch:
	$(CC) $(LIBS) $(INCLUDE) include/pch.h -x $(CFLAGS)
