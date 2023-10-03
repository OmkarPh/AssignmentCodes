#include <iostream>
#include <stdlib.h>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

void backtrack(int r, int n, vector<string> &res, set<int> &col, set<int> &posDiag, set<int> &negDiag)
{
  if (r == n)
  {
    // res.push_back(board);
    res.push_back("gg");
    return;
  }

  for (int c = 0; c < n; c++)
  {
    if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c))
      continue;
    col.insert(c);
    posDiag.insert(r + c);
    negDiag.insert(r - c);
    // board[r][c] = 'Q';

    backtrack(r + 1, n, res, col, posDiag, negDiag);

    col.erase(c);
    posDiag.erase(r + c);
    negDiag.erase(r - c);
    // board[r][c] = '.';
  }
}

vector<string> solveNQueens(int n)
{
  set<int> col;
  set<int> posDiag; // (r +c)
  set<int> negDiag; // (r - c)

  vector<string> res;
  // vector<string> board(n, string(n, '.'));

  backtrack(0, n, res, col, posDiag, negDiag);
  return res;
}

int main()
{
  vector<int> queries = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<string> sols;
  for (int n : queries)
  {
    sols = solveNQueens(n);
    printf("There are %lu solutions for n=%d: \n", sols.size(), n);
  }

  printf("\n");
}