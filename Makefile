CC = gcc
CFLAGS = -O3 -flto -ggdb

.PHONY: clean
all: build/exit.o build/utils.o build/echo.o build/which.o build/kosh

build/kosh: src/main.c build/exit.o build/utils.o build/echo.o build/which.o
	@mkdir -p build/
	$(CC) -o build/kosh src/main.c build/exit.o build/utils.o build/echo.o build/which.o

build/exit.o: src/exit/exit.c
	$(CC) -c -o build/exit.o src/exit/exit.c $(CFLAGS)
build/which.o: src/which/which.c
	$(CC) -c -o build/which.o src/which/which.c $(CFLAGS)
build/echo.o: src/echo/echo.c
	$(CC) -c -o build/echo.o src/echo/echo.c $(CFLAGS)
build/utils.o: src/utils/utils.c
	$(CC) -c -o build/utils.o src/utils/utils.c $(CFLAGS)

clean:
	rm -rf build/*
