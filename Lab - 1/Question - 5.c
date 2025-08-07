// Write a C program to check whether the Host machine is in Little Endian or Big Endian. Enter a number, print the content of each byte location and Convert the Endianness of the same i.e. Little to Big Endian and vice-versa.

#include <stdio.h>

int main()
{
  unsigned int num;
  unsigned char *bytePtr;

  unsigned int test = 1;
  if (*(unsigned char *)&test == 1)
  {
    printf("Host machine is Little Endian.\n");
  }
  else
  {
    printf("Host machine is Big Endian.\n");
  }

  printf("Enter a number: ");
  scanf("%u", &num);

  bytePtr = (unsigned char *)&num;
  printf("Byte contents:\n");
  for (int i = 0; i < sizeof(num); i++)
  {
    printf("Byte %d: %u\n", i, bytePtr[i]);
  }

  unsigned int converted = ((bytePtr[0] << 24) | (bytePtr[1] << 16) | (bytePtr[2] << 8) | bytePtr[3]);
  printf("Converted number (Endianness switched): %u\n", converted);

  return 0;
}