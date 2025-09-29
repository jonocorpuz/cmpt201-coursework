#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *line = NULL;
char *token = NULL;
char *saveptr = NULL;
size_t len = 0;
ssize_t nread;

int main() {
  printf("Please enter some text: ");
  nread = getline(&line, &len, stdin);
  if (nread == -1) {
    perror("ERROR: getline failed.");
    exit(EXIT_FAILURE);
  }

  printf("Tokens:\n");
  token = strtok(line, " ");
  while (token != NULL) {
    printf("   %s\n", token);
    token = strtok(NULL, " ");
  }

  free(token);
  free(line);

  return 0;
}
