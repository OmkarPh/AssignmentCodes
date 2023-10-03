#include <stdio.h>
#define INFINITY 999999

void dijkstra(int n, int G[n][n], int startVertex)
{
    int cost[n][n], distance[n], path[n];
    int visited[n], count, mindistance, nextnode, i, j;
    // pred[] stores the predecessor of each node
    // count gives the number of nodes seen so far
    // create the cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    // initialize pred[],distance[] and visited[]
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startVertex][i];
        path[i] = startVertex;
        visited[i] = 0;
    }
    distance[startVertex] = 0;
    visited[startVertex] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        // nextnode gives the node at minimum distance
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        // check if a better path exists through nextnode
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    path[i] = nextnode;
                }
        count++;
    }

    printf("\nvertex \t Dist from v%d \t Path\n", startVertex);
    for (int i = 0; i < n; i++){
        printf("%d \t %d \t\t %d", i, distance[i], i);
        j = i;
        do
        {
            j = path[j];
            printf("<-%d", j);
        } while (j != startVertex);
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