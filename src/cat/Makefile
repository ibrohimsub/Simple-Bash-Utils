CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
CFLAGS_WC = -Wall -Werror -Wextra
all: clean s21_cat

s21_cat: s21_cat.o
	$(CC) $(CFLAGS_WC) s21_cat.o -o s21_cat

s21_cat.o:
	$(CC) $(CFLAGS) s21_cat.c

test:
	sh test_func_cat.sh
	sh test_leak_cat.sh

clean:
	rm -rf *.o *.out s21_cat

rebuild: clean all

testcat: s21_cat
	../../test/test_cat.sh

test_clang:
	cp ../../materials/linters/.clang-format .clang-format
	clang-format -n *.c
	clang-format -n *.h