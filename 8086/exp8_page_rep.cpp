#include<bits/stdc++.h>

using namespace std; 

bool hasPageInFrame(int page, int *frames, int f){
  for(int i=0; i<f; i++){
    if(frames[i] == page)
      return true;
  }
  return false;
}
int searchPageInFrame(int page, int *frames, int f){
  for(int i=0; i<f; i++){
    if(frames[i] == page)
      return i;
  }
  return -1;
}

void fifoPageReplacement(int n, int f, int *sequence, int *frames){
  /* Testcase
  12 3
  5 1 2 3 5 1 4 5 1 2 3 4
  2

  20 3
  7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
  1
  */

  int hits = 0;
  cout << "FIFO \tPage frame status \n";
  int rear = 0;
  for(int i=0; i<n; i++){
    int page = sequence[i];
    cout << page << " - \t";

    // Page hit
    if(hasPageInFrame(page, frames, f)){
      cout << "---- Page Hit -----" << endl;
      hits++;
      continue;
    }

    // Replace page
    frames[rear] = page;

    rear = (rear+1) % f;

    // Show frame status
    for(int i=0; i<f; i++){
      // if(rear == i)
      //   cout << "[";
      if(frames[i] == -1)
        cout << "-";
      else {
        cout << frames[i];
        if(rear == i)
          cout << "*";
      }

      // if(rear == i)
      //   cout << "]";
      cout << "\t";
    }
    cout << endl;
  }

  cout << endl;
  cout << "Page hits: " << hits << endl;
  cout << "Hit rate: " << hits*100/n << " %" << endl;
}

void lruPageReplacement(int n, int f, int *sequence, int *frames){
  /* Testcase
  13 4
  7 0 1 2 0 3 0 4 2 3 0 3 2
  2

  20 3
  7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
  2
  */
  int hits = 0;
  unordered_map<int, int> lastUsage;

  cout << "LRU \tPage frame status \n";
  for(int i=0; i<n; i++){
    int page = sequence[i];
    cout << page << " - \t";

    // Empty
    if(i<f){
      frames[i] = page;
      lastUsage[page] = i;
      // Show frame status
      for(int i=0; i<f; i++){
        if(frames[i] == -1)
          cout << "-";
        else
          cout << frames[i];
        cout << "\t";
      }
      cout << endl;
      continue;
    }

    // Page hit
    if(hasPageInFrame(page, frames, f)){
      cout << "---- Page Hit -----" << endl;
      hits++;
      lastUsage[page] = i;
      continue;
    }      

    // Replace page
    int lruPage=page, lruTime = i;
    for (auto j = lastUsage.begin(); j != lastUsage.end(); j++){
      if(j->second < lruTime){
        lruPage = j->first;
        lruTime = j->second;
      }
    }
    lastUsage.erase(lruPage);
    // cout << "LRU page (" << lruPage << ")" << "\t";
    int pageIdxInFrames = searchPageInFrame(lruPage, frames, f);
    frames[pageIdxInFrames] = page;
    lastUsage[page] = i;

    // Show frame status
    for(int i=0; i<f; i++){
      if(frames[i] == -1)
        cout << "-";
      else
        cout << frames[i];
      cout << "\t";
    }
    cout << endl;

    // cout << "Last usages: " << endl;
    // for (auto j = lastUsage.begin(); j != lastUsage.end(); j++){
    //   cout << j->first << "(" << j->second << "), ";
    // }
    // cout << endl;
  }
  
  cout << endl;
  cout << "Page hits: " << hits << endl;
  cout << "Hit rate: " << hits*100/n << " %" << endl;
}

int main(){
  int n, f, *sequence, *frames;
  cout << "Enter pages in sequence: ";
  cin >> n;
  cout << "Enter no. of page frames available: ";
  cin >> f;

  sequence = new int[n];
  frames = new int[f];
  cout << "Enter sequence: ";
  for(int i=0; i<n; i++)
    scanf("%d", &sequence[i]);
  for(int i=0; i<f; i++)
    frames[i] = -1;

  cout << "Page replacement algorithm: " << endl;
  cout << "1. FIFO" << endl;
  cout << "2. LRU" << endl;
  int choice;
  cin >> choice;
  switch (choice)
  {
    case 1:
      fifoPageReplacement(n, f, sequence, frames);  
      break;
    case 2:
      lruPageReplacement(n, f, sequence, frames);  
      break;
    default:
      fifoPageReplacement(n, f, sequence, frames);  
      break;
  }

  cout << endl;
  return 0;
}