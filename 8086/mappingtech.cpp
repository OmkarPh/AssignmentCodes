#include<iostream>
#include <cmath>

using namespace std;


void directMapping(){
  long memorySize, cacheSize, blockSize;
  cout << "Direct mapping ------------------------------------" << endl;

  cout << "Memory size (in GB): ";
  cin >> memorySize;
  memorySize *= pow(2, 30);

  cout << "Cache size (in KB): ";
  cin >> cacheSize;
  cacheSize *= pow(2, 10);

  cout << "Line/Block size (in bytes): ";
  cin >> blockSize;

  cout <<endl;
  cout << "Actual memory size: " << memorySize << " bytes" << endl;
  cout << "Actual cache size: " << cacheSize << " bytes" << endl;
  cout << "Actual line/block size: " << blockSize << " bytes" << endl << endl;

  long blocksInMain = memorySize / blockSize;
  long lines = cacheSize / blockSize;
  long lineBits = log2(lines);
  long pages = memorySize / cacheSize;
  long pageBits = log2(pages);
  long wordBits = log2(blockSize);
  long words = pow(2, wordBits);

  cout << "Total blocks in main memory: " << blocksInMain << endl;
  cout << "Total pages: " << pages << endl;
  cout << "Total lines: " << lines << endl;
  cout << "Words in a line: " << words << endl;

  cout << endl << "-------------- Total bits: " << lineBits+pageBits+wordBits << " ---------------" << endl;
  cout << "Page bits: " << pageBits << "\t";
  cout << "Line bits: " << lineBits << "\t";
  cout << "Word bits: " << wordBits << "\t";
  cout << endl << endl;

  // Testcase
  // 1 4 64 4
}


void nWayMapping(){
  cout << "N-way mapping -----------------------------------" << endl;
  long memorySize, cacheSize, blockSize;
  int n;

  cout << "Memory size (in GB): ";
  cin >> memorySize;
  memorySize *= pow(2, 30);

  cout << "Cache size (in KB): ";
  cin >> cacheSize;
  cacheSize *= pow(2, 10);

  cout << "Enter no. of cache: ";
  cin >> n;
  cacheSize /= n;

  cout << "Line/Block size (in bytes): ";
  cin >> blockSize;

  cout <<endl;
  cout << "Actual memory size: " << memorySize << " bytes" << endl;
  cout << "Actual cache size: " << cacheSize << " bytes" << endl;
  cout << "Actual line/block size: " << blockSize << " bytes" << endl << endl;

  long blocksInMain = memorySize / blockSize;
  long lines = cacheSize / blockSize;
  long lineBits = log2(lines);
  long pages = memorySize / cacheSize;
  long pageBits = log2(pages);
  long wordBits = log2(blockSize);
  long words = pow(2, wordBits);

  cout << "Total blocks in main memory: " << blocksInMain << endl;
  cout << "Total pages: " << pages << endl;
  cout << "Total lines: " << lines << endl;
  cout << "Words in a line: " << words << endl;

  cout << endl << "-------------- Total bits: " << lineBits+pageBits+wordBits << " ---------------" << endl;
  cout << "Page bits: " << pageBits << "\t";
  cout << "Line bits: " << lineBits << "\t";
  cout << "Word bits: " << wordBits << "\t";
  cout << endl << endl;


  // Testcase
  // 2 4 64 2 4
}

int main(){
  int choice;
  while (1){
    printf("\n");
    printf("1. Direct mapping \t");
    printf("2. N-way mapping \t");
    printf("3. Exit \n");
    printf("Your choice: ");
    int inputRes = scanf("%d", &choice);
    if(inputRes != 1){
      printf("Something's not right here, I expected a number, Did you enter something else by mistake ...? \n");
      while ((choice = getchar()) != '\n' && choice != EOF);
    }

    switch (choice){
      case 1:
        directMapping();
        break;
      case 2:
        nWayMapping();
        break;
      case 3:
        printf("Bye !!\n");
        return 0;
      default:
        printf("Invalid choice opted! Try again \n");
        break;
    }
  }

  printf("\n");
  return 0;
}