#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int min(int m, int n)
{
  return m <= n ? m : n;
}
int max(int m, int n)
{
  return m >= n ? m : n;
}

void printTable(int m, int n, int matrix[][n], char *s1, char *s2, char *name)
{
  printf("%s: \n", name);

  printf("%5c", ' ');
  for (int j = 0; j < n; j++)
    printf(" %3c", s2[j]);
  printf("\n");

  for (int i = 0; i < m; i++)
  {
    if (i == 0)
      printf("  ");
    else
      printf("%c ", s1[i - 1]);

    for (int j = 0; j < n; j++)
    {
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

char *lcs(char *str1, int m, char *str2, int n)
{
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    dp[i][0] = 0;
  for (int i = 0; i <= n; i++)
    dp[0][i] = 0;

  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = 0;

  printTable(m + 1, n + 1, dp, str1, str2, "DP matrix");
  char currCharRow;
  for (int i = 1; i <= m; i++)
  {
    currCharRow = str1[i - 1];
    for (int j = 1; j <= n; j++)
    {
      if (currCharRow == str2[j - 1])
      {
        dp[i][j] = (dp[i - 1][j - 1]) + 1;
      }
      else
      {
        dp[i][j] = max((dp[i-1][j]), (dp[i][j-1]));
      }
    }
  }
  printTable(m+1, n+1, dp, str1, str2, "DP matrix");
  int lcsLength = dp[m][n];
  char *result = (char*)malloc(sizeof(char) * lcsLength);
  int resultPtr = lcsLength-1;
  int i = m;
  int j = n;
  while(i>0 && j>0){
    int curr = dp[i][j];
    if(curr == dp[i-1][j])  //up
      i--;
    else if(curr == dp[i][j-1]) //left
      j--;
    else {  // diag
      // printf("Diag at %d,%d (%d)\n", i, j, dp[i][j]);
      result[resultPtr] = str1[i-1];
      i--;
      j--;
      resultPtr--;
    }
  }
  return result;
}

int main()
{
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