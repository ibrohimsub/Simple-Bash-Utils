#include "s21_grep.h"

int main(int argc, char *argv[]) {
  init_options();
  check_flags(argc, argv);
  open_file(argc, argv);
  return 0;
}

void check_flags(int argc, char **argv) {
  int rez;
  opterr = 0;

  while ((rez = getopt_long(argc, argv, "e:ivclnhsf:o", flags, 0)) != -1) {
    flag.any_flags = 1;  // if res != -1, it means there is at least one flag
    switch (rez) {
      case 'e':
        flag.e = 1;
        ++characteristics.e_count;
        // printf("%s", optarg);
        flag_e();
        break;
      case 'i':
        flag.i = 1;
        break;
      case 'v':
        flag.v = 1;
        break;
      case 'c':
        flag.c = 1;
        break;
      case 'l':
        flag.l = 1;
        break;
      case 'n':
        flag.n = 1;
        break;
      case 'h':
        flag.h = 1;
        break;
      case 's':
        flag.s = 1;
        break;
      case 'f':
        flag.f = 1;
        flag_f();
        break;
      case 'o':
        flag.o = 1;
        break;
      case '?':
        // printf("Error found !\n");
        exit(1);
    }
  }

  if (characteristics.empty_lines) flag.o = 0;

  // Making a string that we have to find
  if (!flag.e && !flag.f) strcat(observable_string, argv[optind++]);
  //        printf("e: %d\n", flag.e);
  //        printf("i: %d\n", flag.i);
  //        printf("v: %d\n", flag.v);
  //        printf("c: %d\n", flag.c);
  //        printf("l: %d\n", flag.l);
  //        printf("o: %d\n", flag.o);
  //        printf("n: %d", flag.n);
}

void open_file(int argc, char *argv[]) {
  characteristics.files_count = argc - optind;
  while (optind < argc) {
    FILE *file;
    if ((file = fopen(argv[optind], "r")) != NULL) {
      find_and_print(argv, file);
      fclose(file);
    } else if (!flag.s) {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[optind]);
    }
    ++optind;
  }
}

void flag_e() {
  if (characteristics.e_count > 1) strcat(observable_string, "|");
  strcat(observable_string, optarg);
}

void flag_f() {
  FILE *file = NULL;
  char buffer[BUFFSIZE] = {0};

  if ((file = fopen(optarg, "r"))) {
    fseek(file, 0, SEEK_SET);
    while (fgets(buffer, BUFFSIZE, file) != NULL) {
      if (buffer[strlen(buffer) - 1] == '\n') buffer[strlen(buffer) - 1] = 0;
      if (characteristics.e_count > 0) strcat(observable_string, "|");
      if (*buffer == '\0') {
        characteristics.empty_lines = 1;
        strcat(observable_string, ".");
      } else {
        strcat(observable_string, buffer);
      }
      ++characteristics.e_count;
    }
    fclose(file);
  } else {
    printf("File not found\n");
    exit(1);
  }
}

void find_and_print(char *argv[], FILE *file) {
  regex_t regex;  // regcomp() and regexec() Variable that saves compiled
                  // regular expression
  int cflags = REG_EXTENDED;  // regcomp() Flags that add the conditions of
                              // finding a string

  char buffer[BUFFSIZE];  // regexec() Array for line in file
  int nmatch = 1;         // regexec() Length of regmatch_t structure

  // regexec() Structure that saves information of where the looking string is
  regmatch_t regmatch[1] = {0};
  int status;  // Result of regexec()

  size_t last_line_count;
  size_t file_lines_count = 1;
  characteristics.lines_count = 0;

  if (flag.i) cflags |= REG_ICASE;  // Ignore case if flag is i

  regcomp(&regex, observable_string, cflags);

  while (!feof(file)) {
    if (fgets(buffer, BUFFSIZE, file)) {
      int is_new_line = 1;
      status = regexec(&regex, buffer, nmatch, regmatch, 0);
      if (flag.v) status = status ? 0 : 1;
      if (flag.v == 1 && flag.o == 1) flag.o = 0;
      if (status != REG_NOMATCH) {
        if (!flag.c && !flag.l) {
          if (!flag.h && characteristics.files_count > 1)
            printf("%s:", argv[optind]);
          if (flag.n && !flag.o) printf("%lu:", file_lines_count);
          if (flag.o && !flag.v) {
            is_new_line = 0;
            char *ptr = buffer;
            while (!status && regmatch[0].rm_eo != regmatch[0].rm_so) {
              if (!flag.h && characteristics.files_count > 1 &&
                  last_line_count == file_lines_count)
                printf("%s:", argv[optind]);
              if (flag.n) printf("%lu:", file_lines_count);
              printf("%.*s\n", (int)(regmatch[0].rm_eo - regmatch[0].rm_so),
                     ptr + regmatch[0].rm_so);
              ptr += regmatch[0].rm_eo;
              status = regexec(&regex, ptr, nmatch, regmatch, REG_NOTBOL);
              last_line_count = file_lines_count;
            }
          }

          if (!flag.o) printf("%s", buffer);

          if (buffer[strlen(buffer) - 1] != '\n' && is_new_line) printf("\n");
        }
        ++characteristics.lines_count;
      }
      ++file_lines_count;
    }
  }

  // if (flag.c && flag.e) {
  // int current, prev;
  // fseek(file, 0L, SEEK_SET);
  // while ((current = fgetc(file)) != EOF) {
  //   if (prev == '\n' && current == '\n') --characteristics.lines_count;
  //   prev = current;
  // }
  // }

  if (flag.c) {
    if (!flag.h && characteristics.files_count > 1) printf("%s:", argv[optind]);
    if (flag.l && characteristics.lines_count)
      printf("1\n");
    else
      printf("%d\n", characteristics.lines_count);
  }

  if (flag.l && characteristics.lines_count) printf("%s\n", argv[optind]);

  regfree(&regex);
}
