#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n, int matrix[][n], char *name){
    printf("Matrix %s: \n", name);
    for(int i=0; i<n; i++){
        printf("| ");
        for(int j=0; j<n; j++){
            printf("%3d ", matrix[i][j]);
        }
        printf(" |\n");
    }
    printf("\n");
}

void addMatrices(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtractMatrices(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassenMultiplication(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    // allocate memory for sub-matrices
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    int M1[half][half], M2[half][half], M3[half][half], M4[half][half], M5[half][half], M6[half][half], M7[half][half];
    int AA[half][half], BB[half][half];

    // divide A, B and C into sub-matrices
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // compute M1, M2, ..., M7
    subtractMatrices(half, B12, B22, AA);
    strassenMultiplication(half, A11, AA, M1);

    addMatrices(half, A11, A12, AA);
    strassenMultiplication(half, AA, B22, M2);

    addMatrices(half, A21, A22, AA);
    strassenMultiplication(half, AA, B11, M3);

    subtractMatrices(half, B21, B11, AA);
    strassenMultiplication(half, A22, AA, M4);

    addMatrices(half, A11, A22, AA);
    addMatrices(half, B11, B22, BB);
    strassenMultiplication(half, AA, BB, M5);

    subtractMatrices(half, A12, A22, AA);
    addMatrices(half, B21, B22, BB);
    strassenMultiplication(half, AA, BB, M6);

    subtractMatrices(half, A11, A21, AA);
    addMatrices(half, B11, B12, BB);
    strassenMultiplication(half, AA, BB, M7);

    // compute C11, C12, C21, C22
    addMatrices(half, M5, M4, AA);
    subtractMatrices(half, AA, M2, BB);
    addMatrices(half, BB, M6, C11);

    addMatrices(half, M1, M2, C12);
    addMatrices(half, M3, M4, C21);

    subtractMatrices(half, M5, M3, AA);
    subtractMatrices(half, AA, M7, BB);
    addMatrices(half, BB, M1, C22);

    // combine sub-matrices into C
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

int main() {
    int A[4][4] = {
        { 1, 0, 2, -3 },
        { 3, -1, 0, -2 },
        { 1, -3, 2, 0 },
        { -3, 2, 0, 1 },
    };
    int B[4][4] = {
        { 2, 3, -2, 3 },
        { 3, -1, 0, 2 },
        { -1, 0, 1, 0 },
        { 0, 2, -3, -1 },
    };

    int C[4][4];

    strassenMultiplication(4, A, B, C);

    printMatrix(4, A, "A");
    printMatrix(4, B, "B");
    printMatrix(4, C, "Result");

    return 0;
}