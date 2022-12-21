
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage

HEADERS = s21_matrix.h 
SOURCES_ALL = $(wildcard ./CORE/*.c)


OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES_ALL))

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@


all: s21_matrix.a test gcov_report

s21_matrix.a: $(OBJ_LIBRARY) $(HEADERS)
	ar rcs s21_matrix.a $(OBJ_LIBRARY)
	ranlib s21_matrix.a
	rm -rf ./*/*.o

test: s21_matrix.a TESTS/SUITE_main.c
	gcc $(CFLAGS) TESTS/SUITE_main.c s21_matrix.a -o test.out -lm -lcheck
	./test.out

personal: s21_matrix.a TESTS/personal.c
	gcc $(CFLAGS) TESTS/personal.c s21_matrix.a -o test.out -lm -lcheck
	./test.out

gcov_report: s21_matrix.a TESTS/SUITE_main.c
	gcc $(GCOVFLAGS) TESTS/SUITE_main.c $(SOURCES_ALL) -o report.out -lm -lcheck
	./report.out
	gcov -f $(SOURCES_ALL)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html

check:
	clang-format -style=Google -n ./*/*.c

rebuild: clean all

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov
	rm -rf ./report
