#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024

int stack[STACK_SIZE];
int stack_ptr = 0;

void push(char *arg, int line_num) {
  if (arg == NULL || *arg == '\0') {
    fprintf(stderr, "L%d: usage: push integer\n", line_num);
    exit(EXIT_FAILURE);
  }

  int val = atoi(arg);
  if (val == 0 && *arg != '0') {
    fprintf(stderr, "L%d: usage: push integer\n", line_num);
    exit(EXIT_FAILURE);
  }

  if (stack_ptr >= STACK_SIZE) {
    fprintf(stderr, "L%d: error: stack overflow\n", line_num);
    exit(EXIT_FAILURE);
  }

  stack[stack_ptr++] = val;
}

void pall() {
  int i;
  for (i = stack_ptr - 1; i >= 0; i--) {
    printf("%d\n", stack[i]);
  }
}

void execute_instruction(char *opcode, char *arg, int line_num) {
  if (strcmp(opcode, "push") == 0) {
    push(arg, line_num);
  } else if (strcmp(opcode, "pall") == 0) {
    pall();
  } else {
    fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
    exit(EXIT_FAILURE);
  }
}

void parse_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  int line_num = 1;

  while ((nread = getline(&line, &len, fp)) != -1) {
    char *opcode = strtok(line, " \t\n");
    if (opcode == NULL) {
      continue;
    }
    char *arg = strtok(NULL, " \t\n");
    execute_instruction(opcode, arg, line_num);
    line_num++;
  }

  free(line);
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
  }

  parse_file(argv[1]);

  return 0;
}
