#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
  int *queueArray;
  int currCapacity, rear;
} Queue;
Queue* createQueue(){
  const int initiaSize = 20;
  Queue* q = (Queue*)malloc(sizeof(Queue));
  q->queueArray = (int *)malloc(sizeof(int) * initiaSize);
  q->currCapacity = initiaSize;
  q->rear = -1;
  // printf("Initialize queue array \n");
  return q;
}

int front(Queue *q){
  return q->rear > -1 ? q->queueArray[0] : -1;
}
int back(Queue *q){
  return q->rear > -1 ? q->queueArray[q->rear] : -1;
}
int queueSize(Queue *q){
  return q->rear+1;
}
int enqueueEl(Queue *q, int value){
  if(q->rear+1 > q->currCapacity-1){
    printf("Capacity reached, doubling array now \n");
    int *newQueueArray = (int *)malloc(sizeof(int) * q->currCapacity * 2);
    for(int i=0; i<q->currCapacity; i++)
      newQueueArray[i] = q->queueArray[i];
    free(q->queueArray);
    q->queueArray = newQueueArray;
    q->currCapacity *= 2;
  }
  q->rear++;
  q->queueArray[q->rear] = value;
  return q->rear+1;
}
int dequeue(Queue *q){
  if(q->rear < 0)
    return -1;
  int removed = q->queueArray[0];
  for(int i=0; i<q->rear; i++)
    q->queueArray[i] = q->queueArray[i+1];
  q->rear--;
  return removed;
}
void clearQueue(Queue *q){
  q->rear = -1;
}
void printQueue(Queue *q){
  if(q->rear < 0){
    // printf("No elements in queue to print :(\n");
    printf("No cars on this track ---- \n");
    return;
  }
  printf("Queue [Size: %d] (back to front) i.e. %d - 0:\t", q->rear, queueSize(q));
  for(int i=q->rear; i>= 0; i--){
    printf("%d ", q->queueArray[i]);
  }
  printf("\n");
}

void checkAndUpdateResultTrackIfHoldingTrackHasNextOne(int nextExpectedInResult, int holdingTracksCount, Queue *resultTrack, Queue** holdingTracks){
  // Check if next expected car for newly enqueued el, is already in the front of queues
  while(true) {
    bool foundNext = false;
    for(int j=0; j<holdingTracksCount; j++){
      if(front(holdingTracks[j]) == nextExpectedInResult){
        enqueueEl(resultTrack, dequeue(holdingTracks[j]));
        nextExpectedInResult++;
        foundNext = true;
      }
    }
    if(!foundNext)
      break;
  }
}
void printCurrentQueueState(int holdingTracksCount, Queue *resultTrack, Queue** holdingTracks){
  printf("Holding tracks used:\n");
  for(int j=0; j<holdingTracksCount; j++){
    printf("%d. ", j+1);
    printQueue(holdingTracks[j]);
  }
  printf("%d. Pass through track \n", ++holdingTracksCount);
  printf("Result cars position rn: ");
  printQueue(resultTrack);
  printf("\n");
}

int main(){
  /* Testcase in ppt
  9
  5 8 1 7 4 2 9 6 3
  Expected: 3

  9
  1 2 3 4 5 6 7 8 9
  Worst case, Expected: 9

  9
  9 8 7 6 5 4 3 2 1
  Best case, Expected: 1
  */

  Queue *q = createQueue();
  int n;

  printf("Enter no. of train cars: ");
  scanf("%d", &n);

  printf("Enter cars (%d): ", n);
  int *cars = (int *)malloc(sizeof(int)*n);
  int minCar = INT32_MAX;
  bool inOrder = true;
  for(int i=0; i<n; i++){
    // if(cars[i] <)
    scanf("%d", &cars[i]);
    minCar = cars[i] < minCar ? cars[i] : minCar;
  }

  int holdingTracksCount = 0;
  int reservedTracksCount = 20;
  Queue **holdingTracks = (Queue **)malloc(sizeof(Queue*) * reservedTracksCount);
  for(int j=0; j<reservedTracksCount; j++)
    holdingTracks[j] = createQueue();
  Queue *resultTrack = createQueue();

  printf("\nStart Evaluation -----------------------------------------------------------------------------\n\n");
  for(int i=n-1; i>=0; i--){
    int car = cars[i];
    printf("Process car %d\n", car);

    int nextExpectedInResult = back(resultTrack) > 0 ? back(resultTrack) + 1 : minCar;
    if(car == nextExpectedInResult){
      // printf("Next expected went through directly !!\n");
      enqueueEl(resultTrack, car);
      nextExpectedInResult++;
      checkAndUpdateResultTrackIfHoldingTrackHasNextOne(
        nextExpectedInResult,
        holdingTracksCount,
        resultTrack,
        holdingTracks
      );
    } else {
      bool heldCar = false;
      for(int j=0; j<holdingTracksCount; j++){
        if(back(holdingTracks[j]) < car){
          enqueueEl(holdingTracks[j], car);
          heldCar = true;
          break;
        }
      }
      if(!heldCar){
        holdingTracksCount++;
        enqueueEl(holdingTracks[holdingTracksCount-1], car);
      }
    }

    printCurrentQueueState(holdingTracksCount, resultTrack, holdingTracks);
  }
  
  printf("Final result: -----------------------------------------------------------------------------\n");
  printCurrentQueueState(holdingTracksCount, resultTrack, holdingTracks);
  printf("Result cars position: \n");
  printQueue(resultTrack);
  printf("No. of queues required: %d\n", holdingTracksCount+1);
  printf("\n");
}