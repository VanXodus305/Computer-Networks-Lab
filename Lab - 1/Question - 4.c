// Write a C Program to enter a number and store the number across the following structure and print the content of each member of the structure. Then aggregate each member of the structure to form the original number and print the same.
// struct pkt{ char ch1; char ch2[2]; char ch3; };

#include <stdio.h>

struct pkt
{
  unsigned char ch1;
  unsigned char ch2[2];
  unsigned char ch3;
};

void main()
{
  struct pkt p;
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  p.ch1 = (number >> 24) & 0xFF;
  p.ch2[0] = (number >> 16) & 0xFF;
  p.ch2[1] = (number >> 8) & 0xFF;
  p.ch3 = number & 0xFF;

  printf("Structure contents:\n");
  printf("ch1: %d\n", p.ch1);
  printf("ch2[0]: %d\n", p.ch2[0]);
  printf("ch2[1]: %d\n", p.ch2[1]);
  printf("ch3: %d\n", p.ch3);

  int original_number = ((p.ch1 << 24) | (p.ch2[0] << 16) | (p.ch2[1] << 8) | p.ch3);

  printf("Original number: %d\n", original_number);
}