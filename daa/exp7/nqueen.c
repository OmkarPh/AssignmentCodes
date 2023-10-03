#include <stdbool.h>
#include <stdio.h>
 
/* A utility function to print solution */
void printSolution(int n, int board[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(" %c ", board[i][j] == 1 ? 'Q' : '-');
        printf("\n");
    }
}
 
bool isSafe(int n, int board[n][n], int row, int col)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 
bool solveNQUtil(int n, int board[n][n], int col)
{
    /* base case: If all queens are placed
    then return true */
    if (col >= n)
        return true;
 
    /* Consider this column and try placing
    this queen in all rows one by one */
    for (int i = 0; i < n; i++) {
        /* Check if the queen can be placed on
        board[i][col] */
        if (isSafe(n, board, i, col)) {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
 
            /* recur to place rest of the queens */
            if (solveNQUtil(n, board, col + 1))
                return true;
 
            board[i][col] = 0; // BACKTRACK
        }
    }
 
    return false;
}

bool solveNQ()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int board[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            board[i][j] = 0;
 
    if (solveNQUtil(n, board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
 
    printSolution(n, board);
    return true;
}
 
int main()
{
    solveNQ();
    return 0;
}