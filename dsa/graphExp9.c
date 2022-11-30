#include <stdio.h>
#include <stdlib.h>

/* Test case 1
5
0 1 2 3 4
0 1 0 1 0
1 0 1 1 0
0 1 0 1 1
1 1 1 0 0
0 0 1 0 1
2
0

*/

/* Test case 2
8
a b c d e f g h
0 1 1 0 0 0 0 1
1 0 0 1 0 1 0 0
1 0 0 0 1 0 0 0
0 1 0 0 1 1 0 0
0 0 1 1 0 0 1 1
0 1 0 1 0 0 0 0
0 0 0 0 1 0 0 0
1 0 0 0 1 0 0 0
1
0

*/

/* Test case 3 - Class prob
y -- z -- s     t
|       |   /  |    / |
x -- w - v -- u

8
s t u v w x y z
0 0 0 1 1 0 0 1
0 0 1 1 0 0 0 0
0 1 0 1 0 0 0 0
1 1 1 0 1 0 0 0
1 0 1 0 0 1 0 1
0 0 0 0 1 0 1 0
0 0 0 0 0 1 0 1
1 0 0 0 1 0 1 0
1
0

*/


// Queue
#define initialsize 10
int *queueArray, currCapacity = 0;
int rear = -1;

int front(){
  return rear > -1 ? queueArray[0] : -1;
}
int back(){
  return rear > -1 ? queueArray[rear] : -1;
}
int queueSize(){
  return rear+1;
}
int queue(int value){
  if(rear+1 > currCapacity-1){
    if(currCapacity == 0){
      // printf("Initialize queue array \n");
      currCapacity = initialsize;
      queueArray = (int *)malloc(sizeof(int) * currCapacity);
    } else {
      // printf("Capacity reached, doubling array now \n");
      int *newQueueArray = (int *)malloc(sizeof(int) * currCapacity * 2);
      for(int i=0; i<currCapacity; i++)
        newQueueArray[i] = queueArray[i];
      free(queueArray);
      queueArray = newQueueArray;
      currCapacity *= 2;
    }
  }
  queueArray[++rear] = value;
  return rear+1;
}
int dequeue(){
  if(rear < 0)
    return -1;
  int removed = queueArray[0];
  for(int i=0; i<rear; i++)
    queueArray[i] = queueArray[i+1];
  rear--;
  return removed;
}
void clearQueue(){
  rear = -1;
}
void printQueue(){
  if(rear < 0){
    printf("No elements in queue to print :(\n");
    return;
  }
  printf("Queue [Size: %d] (front to back) i.e. 0 - %d:\t", queueSize(), rear);
  for(int i=0; i<=rear; i++){
    printf("%d ", queueArray[i]);
  }
  printf("\n");
}




void resetVisited(int *visited){
     for(int i=0; i<100; i++)
          visited[i] = 0;
}
     
void printGraphMatrix(int **graphMatrix, int vertices){
     printf("\n | ");
     for(int j=0; j<vertices; j++)
          printf("%d ", j);
     printf("\n");
     for(int j=0; j<vertices; j++)
          printf("---");
     printf("\n");
     
     for(int i=0; i<vertices; i++){
          printf("%d| ", i);
          for(int j=0; j<vertices; j++){
               printf("%d ", graphMatrix[i][j]);
          }
          printf("\n");
     }
     printf("\n");
}

void DFS(int sourceNode, char* verticesMapping, int** graphMatrix, int vertices, int* visited){
  if(visited[sourceNode] == 1)
    return;
  // printf("%d ", sourceNode);
  printf("%c ", verticesMapping[sourceNode]);
  visited[sourceNode] = 1;
  for(int i=0; i<vertices; i++){
    if(graphMatrix[sourceNode][i] == 1)
        DFS(i, verticesMapping, graphMatrix, vertices, visited);
  }
}

void BFS(int sourceNode, char* verticesMapping, int** graphMatrix, int vertices, int* visited){
    queue(sourceNode);
    visited[sourceNode] = 1;
    printf("%c ", verticesMapping[sourceNode]);

    int currNode, currChild;
    while(queueSize() > 0){
      int currNode = dequeue();
      // printf("Exploring children of %d\n", currNode);

      for(int i=0; i<vertices; i++){
        // There isn't a connection
        if(graphMatrix[currNode][i] != 1)
          continue;

        // Child already printed by BFS
        if(visited[i] == 1)
            continue;
        queue(i);
        visited[i] = 1;

        // printf("Queued & printed: %d\n", i);
        printf("%c ", verticesMapping[i]);
      }
    }
}

int main() {
  int visited[100];
  resetVisited(visited);
  clearQueue();

  int vertices;
  int** graphMatrix;
  
  printf("Enter no of vertices: ");
  scanf("%d", &vertices);

  char *verticesMapping = (char*)malloc(sizeof(char) * vertices);
  printf("Enter values for graph: ");
  scanf("\n");
  for(int i=0; i<vertices; i++)
    scanf(" %c", &verticesMapping[i]);

  printf("Graph values: ");
  for(int i=0; i<vertices; i++)
    printf("%c ", verticesMapping[i]);
  printf("\n");

  graphMatrix = (int**)malloc(vertices * sizeof(*graphMatrix));
  for (int i = 0; i < vertices; i++) {
    graphMatrix[i] = (int*)malloc(vertices * sizeof(graphMatrix[0]));
  }

  printf("Enter values for adjacency matrix: \n");
  for(int i=0; i<vertices; i++){
      for(int j=0; j<vertices; j++){
            scanf("%d", &graphMatrix[i][j]);
      }
  }

  printf("Graph: ");
  printGraphMatrix(graphMatrix, vertices);

  int choice, source;

  printf("Choosse graph traversal technique: \n1. DFS\t 2. BFS\n");
  printf("Your choice: ");
  scanf("%d", &choice);
  switch(choice){
    case 1:
      printf("Enter source node idx for DFS: ");
      scanf("%d", &source);
      printf("\n");
      printf("Starting DFS from node - %d\nDFS: ", source);
      DFS(source, verticesMapping, graphMatrix, vertices, visited);
      printf("\nDFS done !!\n");
      resetVisited(visited);
      clearQueue();
      break;
    case 2:
      printf("Enter source node idx for BFS: ");
      scanf("%d", &source);
      printf("\n");
      printf("Starting BFS from node - %d\nBFS: ", source);
      BFS(source, verticesMapping, graphMatrix, vertices, visited);
      printf("\nBFS done !!\n");
      resetVisited(visited);
      clearQueue();
      break;
    default:
      printf("Invalid choice opted !!");
      break;
  }

  printf("\n");

  return 0;
}
