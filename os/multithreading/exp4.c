#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ARRAY_SIZE 10000000

int array[ARRAY_SIZE];

void fillArray(){
  srand(time(NULL));
  int count = ARRAY_SIZE;
  for (int i = 0; i < ARRAY_SIZE; i++)
    array[i] = rand();
}

int findLargest(){
  int largest = array[0];
  for (int i = 1; i < ARRAY_SIZE; i++)
    if(array[i] > largest)
      largest = array[i];
  return largest;
}

typedef  struct {
  int start;
  int end;
  int largest;
} ThreadArgs;

void *findLargestInThread(void *argsPtr) {
  ThreadArgs *args = (ThreadArgs *)argsPtr;
  int largest = array[args->start];
  for (int i = args->start + 1; i < args->end; i++)
    if (array[i] > largest)
      largest = array[i];
  args->largest = largest;
  return NULL;
}

int findLargestWithThreads(int n){
  pthread_t threads[n];
  ThreadArgs args[n];
  int partitionSize = ARRAY_SIZE / n;

  for (int i = 0; i < n; i++){
    args[i].start = i * partitionSize;
    args[i].end = (i == n - 1) ? ARRAY_SIZE : (i + 1) * partitionSize;
    pthread_create(&threads[i], NULL, findLargestInThread, &args[i]);
  }

  int largest = array[0];
  for (int i = 0; i < n; i++){
    pthread_join(threads[i], NULL);
    if(args[i].largest > largest)
      largest = args[i].largest;
  }
  return largest;
}

int main(){
  fillArray();

  printf("----------------------------------------------------\n");
  printf("Threads \t Time (seconds) \t Largest \n");
  printf("----------------------------------------------------\n");

  clock_t start = clock();
  int largestWithoutThread = findLargest();
  clock_t end = clock();
  double timeRequired =  (double)(end - start) / CLOCKS_PER_SEC;
  printf("Usual \t\t %lf \t\t %d \n", timeRequired, largestWithoutThread);

  double prevTime = (double)INT32_MAX;
  for (int threads = 1; threads <= 10; threads++) {
    clock_t start = clock();
    int largest = findLargestWithThreads(threads);
    clock_t end = clock();
    
    double timeRequired =  (double)(end - start) / CLOCKS_PER_SEC;
    char symbol = prevTime < timeRequired ? '^' : ' ';
    printf("%d \t\t %lf %c \t\t %d \n", threads, timeRequired, symbol, largest);
    prevTime = timeRequired;
  }

  return 0;
}