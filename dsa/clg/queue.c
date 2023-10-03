#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int *queueArray;
  int currCapacity, rear;
} Queue;
Queue* createQueue(){
  const int initiaSize = 20;
  Queue* q = (Queue*)malloc(sizeof(Queue));
  printf("Initialize queue array \n");
  q->queueArray = (int *)malloc(sizeof(int) * initiaSize);
  q->currCapacity = initiaSize;
  q->rear = -1;
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
int queueEl(Queue *q, int value){
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
    printf("No elements in queue to print :(\n");
    return;
  }
  printf("Queue [Size: %d] (front to back) i.e. 0 - %d:\t", queueSize(q), q->rear);
  for(int i=0; i<=q->rear; i++){
    printf("%d ", q->queueArray[i]);
  }
  printf("\n");
}



int main(){
  Queue *q = createQueue();
  int choice, el;
  while (1){
    printf("\n");
    printf("1. Queue \t");
    printf("2. DeQueue \t");
    printf("3. Show front, back & size of Queue \t");
    printf("4. Show entire queue \t");
    printf("5. Clear Queue \t");
    printf("5. Exit \n");
    printf("Your choice: ");
    int inputRes = scanf("%d", &choice);
    if(inputRes != 1){
      printf("Something's not right here, I expected a number, Did you enter something else by mistake ...? \n");
      while ((choice = getchar()) != '\n' && choice != EOF);
    }

    switch (choice){
      case 1:
        printf("Enter the number to queue: ");
        scanf("%d",&el);
        int len = queueEl(q, el);
        printf("Number added to queue, updated size of queue: %d\n", len);
        printQueue(q);
        break;
      case 2:
        printf("Dequeued: %d\n", dequeue(q));
        printQueue(q);
        break;
      case 3:
        printf("Front: %d, back: %d, size: %d, max capacity: %d\n", front(q), back(q), queueSize(q), q->currCapacity);
        printQueue(q);
        break;
      case 4:
        printQueue(q);
        break;
      case 5:
        clearQueue(q);
        printQueue(q);
        break;
      case 6:
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