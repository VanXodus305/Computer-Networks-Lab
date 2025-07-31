// Write a C program to swap the content of 2 variables using pointer.

#include <stdio.h>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main()
{
  int x, y;

  printf("Enter first number: ");
  scanf("%d", &x);
  printf("Enter second number: ");
  scanf("%d", &y);

  printf("Before swapping: x = %d, y = %d\n", x, y);

  swap(&x, &y);

  printf("After swapping: x = %d, y = %d\n", x, y);

  return 0;
}