

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void printTable(int m, int n, int matrix[m][n], char *name)
{
  printf("%s: \n", name);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void printEntireTable(int m, int n, int matrix1[m][n], int matrix2[m][n], int matrix3[m][n], char *name1, char *name2, char *name3)
{
  printf("\t%s \t  %s \t  %s \n", name1, name2, name3);
  for (int i = 0; i < m; i++)
  {
    printf("P%d\t", i);
    for (int j = 0; j < n; j++){
      printf("%d ", matrix1[i][j]);
    }
    printf("\t ");
    for (int j = 0; j < n; j++){
      printf("%d ", matrix2[i][j]);
    }
    printf("\t ");
    for (int j = 0; j < n; j++){
      printf("%d ", matrix3[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


int main()
{
  /*
  Input

5 3

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

3 3 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

7 4 3
1 2 2
6 0 0
0 1 1
4 3 1

*/

  int processes, resources;
  printf("Enter no. of processes: ");
  scanf("%d", &processes);
  printf("Enter no. of resources: ");
  scanf("%d", &resources);
  printf("\n");

  int allocation[processes][resources];
  int max[processes][resources];
  int need[processes][resources];

  printf("\nEnter allocation:\n");
  for (int i = 0; i < processes; i++)
  {
    for (int j = 0; j < resources; j++)
    {
      scanf("%d", &allocation[i][j]);
    }
  }

  printf("\nEnter max:\n");
  for (int i = 0; i < processes; i++)
  {
    for (int j = 0; j < resources; j++)
    {
      scanf("%d", &max[i][j]);
    }
  }

  printf("\nEnter need:\n");
  for (int i = 0; i < processes; i++)
  {
    for (int j = 0; j < resources; j++)
    {
      scanf("%d", &need[i][j]);
    }
  }
  printf("\n");
  printEntireTable(processes, resources, allocation, max, need, "Alloc", "Max", "Need");
  // printTable(processes, resources, allocation, "Allocation");
  // printTable(processes, resources, max, "Max");
  // printTable(processes, resources, need, "Need");

  return 0;
}