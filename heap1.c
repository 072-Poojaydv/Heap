#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct family
{
  char name[30];
  int age;
};
struct family *add(char *name, int age)
{
  struct family *newmem = (struct family *)malloc(sizeof(struct family));               //Adding family members name and age 
  strcpy(newmem->name, name);
  newmem->age = age;
  return newmem;
}
void minheap(struct family **family_heap, int index)                                        // doing functionality of min heap
{
  int child = index;
  int temp;
  int parent;
  char str[20];
  while (child > 0)
  {
    parent = (child - 1) / 2;
    if (family_heap[child]->age < family_heap[parent]->age)
    {
      strcpy(str, family_heap[child]->name);
      strcpy(family_heap[child]->name, family_heap[parent]->name);
      strcpy(family_heap[parent]->name, str);
      temp = family_heap[child]->age;
      family_heap[child]->age = family_heap[parent]->age;
      family_heap[parent]->age = temp;
      child = parent;
    }
    else
      break;
  }
}
int main()
{
  int n, age, i, j;
  char name[20];
  printf("\n **************************************************HEAP DATA **********************************************************\n");
  printf("Enter your family members count::\n");
  scanf("%d", &n);
  struct family **family_heap = (struct family **)malloc(sizeof(struct family *) * n);
  for (i = 0; i < n; i++)
  {
    printf("Enter name and age of family members\n");
    printf("Enter data \n");
    scanf("%s %d", name, &age);
    family_heap[i] = add(name, age);
    minheap(family_heap, i);
    printf("(current heap status)\n");
    for (j = 0; j <= i; j++)
      printf("%s \t------>\t %d \n", family_heap[j]->name, family_heap[j]->age);
    printf("\n");
  }
}
