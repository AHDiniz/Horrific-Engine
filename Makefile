ifeq ($(OS), Windows_NT)
CC = g++
AR = ar rcs
CFLAGS = -Wall -Wextra -ggdb -pedantic -lraylib -lopengl32 -lgdi32 -lwinmm -lm -static -std=c++17
LIBS = -Lvendor/raylib/lib/windows
else
CC = g++
AR = ar rcs
CFLAGS = -Wall -Wextra -ggdb -pedantic -lraylib -lGL -lm -lpthread -ldl -lX11 -std=c++17
LIBS = -Lvendor/raylib/lib/linux
endif

EXE = bin/horrific
LIB = lib/horrific.a

INCLUDE = -Iinclude/ -Ivendor/raylib/include/ -Ivendor/json
SOURCE = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard include/*.hpp) $(wildcard include/**/*.hpp)
OBJS = $(wildcard src/*.o) $(wildcard src/**/*.cpp)

horrific: $(wildcard src/*.cpp) $(wildcard include/*.hpp) $(wildcard src/**/*.cpp) $(wildcard include/**/*.hpp)
	$(CC) $(LIBS) $(INCLUDE) -c $(SOURCE) $(CFLAGS) && $(AR) $(LIB) *.o

bindirs:
	mkdir bin/ && mkdir lib/

run:
	./$(EXE)

pch:
	$(CC) include/pch.h -x -lm -std=c++17

clean:
	rm *.o
