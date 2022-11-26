#include <stdio.h>
#include <stdlib.h>


/* Test case 1
4
0 1 0 1
1 0 1 1
0 1 0 1
1 1 1 0
0
*/



/* Test case 2
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
0
*/



/* Test case 3
4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0
*/



/* Test case 5
5
0 1 0 1 0
1 0 1 1 0
0 1 0 1 0
1 1 1 0 0
0 0 0 0 0
0
*/

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

void DFS(int sourceNode, int** graphMatrix, int vertices, int* visited){
     if(visited[sourceNode] == 1)
          return;
     // printf("Visited node %d\n", sourceNode);
     printf("%d ", sourceNode);
     visited[sourceNode] = 1;
     for(int i=0; i<vertices; i++){
          if(graphMatrix[sourceNode][i] == 1)
               DFS(i, graphMatrix, vertices, visited);
     }
}


int main()
{
     int visited[100];
     resetVisited(visited);

     int vertices;
     int** graphMatrix;
     
     printf("Enter vertices: ");
     scanf("%d", &vertices);
     
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

     int source;     
     printf("Enter source node: ");
     scanf("%d", &source);
     
     printf("\n");
     printf("Starting DFS from node - %d\nDFS: ", source);
     DFS(source, graphMatrix, vertices, visited);
     printf("\nDFS done !!\n");
     resetVisited(visited);
     printf("\n");

     printf("\n");
     printf("Starting BFS from node - %d\nBFS: ", source);
     DFS(source, graphMatrix, vertices, visited);
     printf("\nBFS done !!\n");
     resetVisited(visited);
     printf("\n");
          
    return 0;
}
