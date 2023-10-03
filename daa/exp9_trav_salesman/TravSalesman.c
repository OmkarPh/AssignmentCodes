#include <stdio.h>

#define MAX 10
#define INF 99999

void tsp(int adjacency_matrix[MAX][MAX], int n) {
  int visited[MAX], distance = 0, count, current_city = 0, i, j, next_city;

  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }

  visited[current_city] = 1;
  count = 1;

  printf("Path: %d -> ", current_city + 1);

  while (count < n) {
    int min_distance = INF;

    for (i = 0; i < n; i++) {
      if (adjacency_matrix[current_city][i] != 0 && visited[i] == 0) {
        if (adjacency_matrix[current_city][i] < min_distance) {
          min_distance = adjacency_matrix[current_city][i];
          next_city = i;
        }
      }
    }

    distance += min_distance;
    current_city = next_city;
    visited[current_city] = 1;
    count++;

    printf("%d -> ", current_city + 1);
  }

  distance += adjacency_matrix[current_city][0];
  printf("%d\n", 1);
  printf("Tour Distance: %d\n", distance);
}

int main() {
  /*
  Testcase
5
0 12 10 19 8
12 0 3 7 6
10 8 0 2 20
19 7 2 0 4
8 6 20 4 0 

Path: 1,5,4,3,2,1
Dist - 34
  */
  int adjacency_matrix[MAX][MAX], i, j, n;

  printf("No. of vertices: ");
  scanf("%d", &n);

  printf("Adjacency matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &adjacency_matrix[i][j]);
    }
  }

  printf("\nSolution: \n");
  tsp(adjacency_matrix, n);

  return 0;
}
