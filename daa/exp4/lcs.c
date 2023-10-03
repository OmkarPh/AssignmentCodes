#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int min(int m, int n){
    return m <= n ? m : n;
}
int max(int m, int n){
    return m >= n ? m : n;
}

void printTable(int m, int n, int matrix[][n], char *s1, char *s2, char *name){
    printf("%s: \n", name);

    printf("%5c", ' ');
    for(int j=0; j<n; j++)
        printf(" %3c", s2[j]);
    printf("\n");


    for(int i=0; i<m; i++){
        if(i==0)
            printf("  ");
        else
            printf("%c ", s1[i-1]);

        for(int j=0; j<n; j++){
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

char* lcs(char *s1, int m, char *s2, int n){
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = 0;

    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(
                    dp[i-1][j],
                    dp[i][j-1]
                );
        }
    }

    
    printTable(m+1, n+1, dp, s1, s2, "LCS table");


    int resultSize = dp[m][n];
    char *result = (char*)malloc(sizeof(char)*resultSize);

    int resIdx = resultSize-1;
    int tI = m, tJ = n;
    int curr;
    while(tI > 0 || tJ > 0){
        curr = dp[tI][tJ];

        // Left
        if(curr == dp[tI][tJ-1]){
            // printf("Left [%d][%d] -> [%d][%d]\n", tI, tJ, tI, tJ-1);
            tJ--;
            continue;
        }

        // Up
        if(curr == dp[tI-1][tJ]){
            // printf("Up [%d][%d] -> [%d][%d]\n", tI, tJ, tI-1, tJ);
            tI--;
            continue;
        }

        // Diagonal
        // printf("Diagonal (%c) [%d][%d] -> [%d][%d]\n", s2[tJ-1], tI, tJ, tI-1, tJ-1);
        result[resIdx--] = s2[tJ-1];
        tI--;
        tJ--;

        // if(curr == dp[tI-1][tJ-1]){
        //     tI--;
        //     tJ--;
        //     continue;
        // }
    }
    return result;
}

int main(){
    /* Testcases
    gtaatctaac  gattaca
    abaaba  babba
    mzjawxu  xmjyauz
    */
   
    printf("\n");
    // char *s1 = "abaaba";
    // char *s2 = "babbab";
    char s1[100], s2[100];
    printf("Enter string1: ");
    scanf("%s", s1);
    printf("Enter string2: ");
    scanf("%s", s2);

    int m = strlen(s1);
    int n = strlen(s2);
    printf("Strings: \n%s (%d)\n%s (%d)\n\n", s1, m, s2, n);

    char *longestCommonSubsequence = lcs(s1, m, s2, n);
    printf("LCS: %s (%ld)\n", longestCommonSubsequence, strlen(longestCommonSubsequence));

    printf("\n");
    return 0;
}