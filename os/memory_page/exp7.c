#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096

int main(int argc, char *argv[]){
  if (argc < 2){
    printf("Please provide virtual addrss as argument !");
    return 1;
  }

  // Convert command-line argument to unsigned int
  unsigned int addr = atoi(argv[1]);

  unsigned int page_num = addr / PAGE_SIZE;
  unsigned int offset = addr - page_num * PAGE_SIZE;

  // Print results
  // printf("Page size is %d\n", PAGE_SIZE);
  // printf("Page base addr is %d\n", PAGE_SIZE*page_num);
  // printf("Base addr (%d) + offset (%d) = %d\n", PAGE_SIZE*page_num, offset, PAGE_SIZE*page_num+offset);
  printf("The address %u contains:\n", addr);
  printf("page number = %u\n", page_num);
  printf("offset = %u\n", offset);

  return 0;
}