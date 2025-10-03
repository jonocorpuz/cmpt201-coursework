#define _DEFAULT_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct header {
  uint64_t size;
  struct header *next;
};

int main() {
  void *newMemBlock = sbrk(256);
  if (newMemBlock == (void *)-1) {
    perror("ERROR: Srbk() failed");
    return 1;
  }

  size_t dataSize = (256 - 2 * sizeof(struct header));
  size_t numInts = ((dataSize / sizeof(int) / 2));

  struct header *block1 = (struct header *)newMemBlock;
  struct header *block2 =
      (struct header *)(newMemBlock + sizeof(struct header) + numInts);

  block1->size = dataSize;
  block1->next = block2;

  block2->size = dataSize;
  block2->next = NULL;

  int *data1 = (int *)(block1 + 1);
  int *data2 = (int *)(block2 + 1);
  for (size_t i = 0; i < (numInts); i++) {
    data1[i] = 0;
    data2[i] = 1;
  }

  printf("first block: %p\n", block1);
  printf("second block: %p\n", block2);
  printf("first block size: %lu\n", block1->size);
  printf("first block next: %p\n", block1->next);
  printf("second block side: %lu\n", block2->size);
  printf("second block next: %p\n", block2->next);

  for (size_t i = 0; i < numInts; i++) {
    printf("%d\n", data1[i]);
  }

  for (size_t i = 0; i < numInts; i++) {
    printf("%d\n", data2[i]);
  }
}
