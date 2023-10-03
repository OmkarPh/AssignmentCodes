#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<stdlib.h>

#define MAX_SIZE 100

// function to print the optimal parenthesization of a matrix chain
void print_optimal_parens(int s[MAX_SIZE][MAX_SIZE], int i, int j, char name) {
    if (i == j) {
        printf("%c", name++);
    } else {
        printf("(");
        print_optimal_parens(s, i, s[i][j], name);
        print_optimal_parens(s, s[i][j]+1, j, name+s[i][j]-i+1);
        printf(")");
    }
}

void printTable(int n, int matrix[n][n], char *name){
    printf("%s: \n", name);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%5d ", matrix[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}

// function to compute the minimum cost of matrix multiplication using dynamic programming
int matrix_chain_order(int p[], int n, char name) {
    // int s[n+1][n+1];

    // 1 extra for 1 based idx
    int m[n][n];
 
    int j, q;
 
    // For pretty printing in table
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            m[i][j] = 0;
        }
    }

    // Diagonal
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
 
    for(int diagonalSource=2; diagonalSource<n; diagonalSource++){
        for(int diagonalTraveller=diagonalSource; diagonalTraveller<n; diagonalTraveller++){
            
        }
    }

    // L is chain length.
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    printTable(n, m, "Matrix chain DP table");

    // printf("\n");
    // printf("Optimal parenthesization: ");
    // print_optimal_parens(s, 1, n, name);
    // printf("\n");

    return m[1][n-1];
}

int main() {
    printf("\n");
    int matrixSizesLength;

    // Example - https://www.javatpoint.com/matrix-chain-multiplication-example
    int matrix_sizes[] = {4, 10, 3, 12, 20, 7};
    matrixSizesLength = sizeof(matrix_sizes) / sizeof(matrixSizesLength);

    // num_matrices = 10;
    // int matrix_sizes[num_matrices];
    // const int MATRIX_SIZE_LOWER_LIMIT = 15;
    // const int MATRIX_SIZE_UPPER_LIMIT = 46;
    // for(int i=0; i<num_matrices; i++){
    //     matrix_sizes[i] = (rand() % (MATRIX_SIZE_UPPER_LIMIT - MATRIX_SIZE_LOWER_LIMIT + 1)) + MATRIX_SIZE_LOWER_LIMIT;
    // }

    printf("Matrix sizes(%d): ", matrixSizesLength);
    for(int i=0; i<matrixSizesLength; i++){
        printf("%d ", matrix_sizes[i]);
    }
    printf("\n");

    // compute the minimum cost and optimal parenthesization using dynamic programming
    printf("Minimum cost of matrix multiplication: %d\n", matrix_chain_order(matrix_sizes, matrixSizesLength, 'A'));

    printf("\n");
    return 0;
}
