#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 8192

static char observable_string[BUFFSIZE] = {0};

void check_flags(int argc, char* argv[]);
void open_file(int argc, char* argv[]);
void flag_e();
void flag_f();

void find_and_print(char* argv[], FILE* file);

struct characteristics {
  int lines_count;
  int files_count;
  int empty_lines;
  int e_count;
} characteristics;

struct option flags[] = {
    {"e", no_argument, 0, 'e'},  // -e
    {"i", no_argument, 0, 'i'},  // -i
    {"v", no_argument, 0, 'v'},  // -v
    {"c", no_argument, 0, 'c'},  // -c
    {"l", no_argument, 0, 'l'},  // -l
    {"n", no_argument, 0, 'n'},  // -n
    {"h", no_argument, 0, 'h'},  // -h
    {"s", no_argument, 0, 's'},  // -s
    {"f", no_argument, 0, 'f'},  // -f
    {"o", no_argument, 0, 'o'},  // -o
};

struct flag {
  int e;  // For regex
  int i;  // Ignores case
  int v;  // Inverts result of searching
  int c;  // Number of lines where searching string is found
  int l;  // Number of files where searching string is found
  int n;  // Line number in the output of the searched string
  int h;  // Doesn't show files where searching string is found
  int s;  // Doesn't show messages about files that weren't found or couldn't be
          // read
  int f;  // Gets regular expressions from file (needs arguments)
  int o;  // Shows only searched string without full line
  int any_flags;
} flag;

void init_options() {
  flag.e = 0;
  flag.i = 0;
  flag.v = 0;
  flag.c = 0;
  flag.l = 0;
  flag.n = 0;
  flag.h = 0;
  flag.s = 0;
  flag.f = 0;
  flag.o = 0;

  characteristics.lines_count = 0;
  characteristics.files_count = 0;
  characteristics.empty_lines = 0;
  characteristics.e_count = 0;
}

#endif  // SRC_GREP_S21_GREP_H_
