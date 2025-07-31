// Write a C program to assign values to each members of the following structure. Pass the populated structure to a function Using call-by address and print the value of each member of the structure with in that function.
//  struct info{ int roll_no; char name[50]; float CGPA; }

#include <stdio.h>
#include <string.h>

struct info
{
  int roll_no;
  char name[50];
  float CGPA;
};

void print_info(struct info *student)
{
  printf("Roll No: %d\n", student->roll_no);
  printf("Name: %s\n", student->name);
  printf("CGPA: %.2f\n", student->CGPA);
}

void main()
{
  struct info student1;

  printf("Enter Roll No: ");
  scanf("%d", &student1.roll_no);
  printf("Enter Name: ");
  scanf(" %[^\n]", student1.name);
  printf("Enter CGPA: ");
  scanf("%f", &student1.CGPA);

  print_info(&student1);
}