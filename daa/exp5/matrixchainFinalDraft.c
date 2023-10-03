#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

void matrixChainOrder(long long int c[10][10], long long int k[10][10], int p[11])
{
    int n = 10;
    for (int i = 0; i < 10; i++)
    {
        c[i][i] = 0;
    }
    int j;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;

            int min = INT_MAX, k_min = 0;

            for (int k = i; k < j; k++)
            {
                int temp = c[i-1][k-1] + c[(k+1)-1][j-1] + (p[i - 1] * p[k] * p[j]);
                if (temp < min)
                {
                    min = temp;
                    k_min = k;
                }
            }

            c[i-1][j-1] = min;
            k[i-1][j-1] = k_min;
        }
    }

}

void printParenthesis(long long int k[10][10], int i, int j)
{
    if (i == j)
    {
        printf("A%d",i);
        return;
    }
    
    printf("(");
    printParenthesis(k, i, k[i-1][j-1]);
    printParenthesis(k, k[i-1][j-1] + 1, j);
    printf(")");
}

void printMatrix(long long int m[10][10])
{
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(j<i)
            {
                printf("--\t");
            }
            else
            {
                printf("%lld\t", m[i][j]);
            }
        }
        printf("\n");
    }
}


int main()
{
    int p[11];
    // srand(time(0));
    for (int i = 0; i < 11; i++)
    {
        p[i] = (rand() % (46 - 15 + 1)) + 15;
    }

    printf("\nDimensions: ");
    for (int i = 0; i <11; i++)
    {
        printf("%d, ", p[i]);
    }
    printf("\n");

    long long int c[10][10], k[10][10];

    for(int i = 0;i<10;i++)
    {
        k[i][i] = 0;
    }

    clock_t t;
    t = clock();
    matrixChainOrder(c, k, p);
    printf("\nCosts:");
    printMatrix(c);

    printf("\nIdx:");
    printMatrix(k);
    printf("\n");
    
    printf("\nMinimum cost of matrix multiplication: %lld\n\n",c[0][9]);
    printf("Optimal parenthesization: ");
    printParenthesis(k, 1, 10);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    
    printf("\n\nTime taken: %f",time_taken);
    printf("\n");
}