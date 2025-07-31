// Write a C program to extract each byte from a given number and store them in separate character variables and print the content of those variables.

#include <stdio.h>
#include <stdint.h>

int main()
{
  uint32_t number;
  char bytes[4];

  printf("Enter a number: ");
  scanf("%u", &number);

  bytes[0] = (number & 0xFF);
  bytes[1] = (number >> 8) & 0xFF;
  bytes[2] = (number >> 16) & 0xFF;
  bytes[3] = (number >> 24) & 0xFF;

  // Print the content of each byte
  printf("Bytes extracted from the number:\n");
  for (int i = 0; i < 4; i++)
  {
    printf("Byte %d: %d\n", i + 1, bytes[i]);
  }

  return 0;
}