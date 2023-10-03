#include <stdio.h>
#define INFINITY 999999
# define TRUE 1
# define FALSE 0

void printPath(int n, int parents[n], int vertex){
    // for(int i=0;i<n; i++){
    //     printf("%d, ", parents[i]);
    // }
    // return;

    // printf("%d", vertex);
    // vertex = parents[vertex];
    // while(vertex != -1){
    //     printf(" -> %d", vertex);
    //     vertex = parents[vertex];
    // }

    int sequence[n];
    int target=-1;

    while(vertex != -1){
        // printf(" -> %d", vertex);
        sequence[++target] = vertex;
        vertex = parents[vertex];
    }

    printf("%d", sequence[target--]);
    while(target > -1){
        printf(" -> %d", sequence[target--]);
    }
}

void dijkstra(int n, int G[n][n], int startVertex)
{
    int distance[n], parents[n];
    int visited[n]; // instead of bool, using 0 or 1

    for(int i=0; i<n; i++){
        visited[i] = FALSE;
        distance[i] = G[startVertex][i] > 0 ? G[startVertex][i] : INFINITY;
        parents[i] =  G[startVertex][i] > 0 ? startVertex : -1;
    }
    distance[startVertex] = 0;
    visited[startVertex] = TRUE;
    parents[startVertex] = -1;

    for(int i=0; i<n; i++){
        int currVertexDist = INFINITY, currVertex = -1;
        for(int j=0; j<n; j++){
            if(!visited[j] && distance[j] < currVertexDist){
                currVertex = j;
                currVertexDist = distance[j];
            }
        }
        if(currVertexDist == INFINITY){
            printf("All connected vertices are visited !!\n");
            break;
        }
        printf("Selected %d (%d)\n", currVertex, currVertexDist);

        // test & update neighbors
        for(int j=0; j<n; j++){
            if(visited[j] || !G[currVertex][j]) // visited already, or not connected
                continue;
            if(currVertexDist+G[currVertex][j] < distance[j]){
                distance[j] = currVertexDist + G[currVertex][j];
                parents[j] = currVertex;
            }
        }
        // printf("vertex \t Dist from v%d \t Path\n", startVertex);
        // for (int i = 0; i < n; i++){
        //     printf("%d \t %d \t\t", i, distance[i]);
        //     printPath(n, parents, i);
        //     printf("\n");
        // }
        // printf("\n");
        visited[currVertex] = TRUE;
    }

    printf("\nvertex \t Dist from v%d \t Path\n", startVertex);
    for (int i = 0; i < n; i++){
        printf("%d \t %d \t\t", i, distance[i]);
        printPath(n, parents, i);
        printf("\n");
    }
}

// Testcase
/*
5
0 4 8 0 0
4 0 2 5 0
8 2 0 5 9
0 5 5 0 4
0 0 9 4 0

Start 0
Expected 13

https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.devglan.com%2Fdatastructure%2Fdijkstra-algorithm-java&psig=AOvVaw19DwQpGr5o3VeaLpPO4qKL&ust=1681277029463000&source=images&cd=vfe&ved=0CBEQjRxqFwoTCOC3vqKLof4CFQAAAAAdAAAAABAg


9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

Start 0
Expected 14

GfG dijkstra's
*/



int main()
{
    int i, j, n, u;
    printf("\nEnter no. of vertices: ");
    scanf("%d", &n);
    int G[n][n];
    printf("\nEnter Adjacency matrix: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("\nEnter the starting node: ");
    scanf("%d", &u);
    dijkstra(n, G, u);
    return 0;
}
