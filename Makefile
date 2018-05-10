CFLAGS = -Wall -Werror -std=c99
CC = gcc
OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD = mkdir -p build/src

.PHONY: clean test

default: bin/chessviz.exe

test: bin/chessviz_test.exe
	$<

bin/chessviz_test.exe: build/main_test.o build/board.o build/board_read.o
	mkdir -p bin
	$(CC) $^ -o $@ $(CFLAGS)

build/main_test.o: test/main.c thirdparty/ctest.h test/board_test.c
	mkdir -p build/test
	$(OBJ) -I thirdparty -I src

bin/chessviz.exe: build/main.o build/board_print_html.o build/board.o build/board_read.o
	mkdir -p bin
	$(CC) $^ -o $@ $(CFLAGS)

build/main.o: src/main.c
	$(MKDIR_BUILD)
	$(OBJ)

build/board_print_html.o: src/board_print_html.c src/board_print_html.h
	$(MKDIR_BUILD)
	$(OBJ)

build/board.o: src/board.c src/board.h
	$(MKDIR_BUILD)
	$(OBJ)

build/board_read.o: src/board_read.c src/board_read.h
	$(MKDIR_BUILD)
	$(OBJ)

clean:
	rm -rf build bin