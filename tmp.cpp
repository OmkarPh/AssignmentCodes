#include <bits/stdc++.h>
using namespace std;

vector<int> idealDays(vector<int> rainFallPredictions, int k)
{
  int n = rainFallPredictions.size();

  vector<int> forward(rainFallPredictions.size());
  for (int i = 1; i < rainFallPredictions.size(); ++i)
  {
    if (rainFallPredictions[i - 1] >= rainFallPredictions[i])
    {
      forward[i] = forward[i - 1] + 1;
    }
  }

  vector<int> backward(rainFallPredictions.size());
  for (int i = rainFallPredictions.size() - 2; i >= 0; --i)
  {
    if (rainFallPredictions[i + 1] >= rainFallPredictions[i])
    {
      backward[i] = backward[i + 1] + 1;
    }
  }

  vector<int> v;
  for (int i = 0; i < rainFallPredictions.size(); ++i)
  {
    if (forward[i] >= k && backward[i] >= k)
    {
      v.push_back(i);
    }
  }

  return v;
}
int main()
{
  vector<int> v;

  v = idealDays({1,0,0,0,1}, 2);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout<<endl;


  v= idealDays({1,0,1,0,1}, 1);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout<<endl;

  cout<<endl;
}