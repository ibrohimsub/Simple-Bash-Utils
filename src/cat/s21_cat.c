#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int rez = 0, b = 0, e = 0, n = 0, s = 0, t = 0, v = 0, exit = 0;
  const char *short_options = "beEstTnv";
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};
  while ((rez = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    switch (rez) {
      case 'b':
        b = 1;
        break;
      case 'e':
        e = 1;
        v = 1;
        break;
      case 'E':
        e = 1;
        break;
      case 'n':
        n = 1;
        break;
      case 's':
        s = 1;
        break;
      case 't':
        t = 1;
        v = 1;
        break;
      case 'T':
        t = 1;
        break;
      case 'v':
        v = 1;
        break;
      default:
        fprintf(stderr, "cat: illegal option -- %c\n", rez);
        fprintf(stderr, "usage: cat [-benstuv] [file ...]\n");
        exit = 1;
        break;
    }
  }
  if (!exit) {
    while (optind < argc) {
      open_file(argv, b, e, n, s, t, v);
      optind++;
    }
  }
  return 0;
}

void open_file(char *argv[], int b, int e, int n, int s, int t, int v) {
  FILE *fp = NULL;
  if (b && n) n = 0;
  fp = fopen(argv[optind], "r+");
  if (!fp) {
    fprintf(stderr, "cat: %s: %s\n", argv[optind], strerror(errno));
  } else {
    s21_cat(b, e, n, s, t, v, fp);
    fclose(fp);
  }
}

void s21_cat(int b, int e, int n, int s, int t, int v, FILE *fp) {
  int current, prev = 1, temp = 0, count = 1, first = 1;
  while ((current = fgetc(fp)) != EOF) {
    if (s) {
      if (current == '\n') temp++;
      if (current != '\n') temp = 0;
    }
    if (current == '\n' && (!s || temp < 3)) {
      if ((first == 1 && n) || (n && prev == '\n')) printf("%6d\t", count++);
      if (e) {
        if ((prev == '\n' || first == 1) && b) printf("      	");
        printf("$");
      }
      printf("%c", current);
    }
    if (current != '\n') {
      if ((prev == '\n' || first == 1) && (n || b)) printf("%6d\t", count++);
      if (current < 32 && current != 9 && current != 10 && v)
        printf("^%c", current + 64);
      else if (current > 127 && current < 160 && v)
        printf("M-^%c", current - 64);
      else if (current == 127 && v)
        printf("^%c", current - 64);
      else if (current == '\t' && t)
        printf("^I");
      else
        printf("%c", current);
    }
    prev = current;
    first = 0;
  }
}
