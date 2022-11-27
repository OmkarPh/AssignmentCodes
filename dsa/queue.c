#include <stdio.h>
#include <stdlib.h>

#define initiaSize 10
int *queueArray, currCapacity = 0;
int rear = -1;

int front(){
  return rear > -1 ? queueArray[0] : -1;
}
int back(){
  return rear > -1 ? queueArray[rear] : -1;
}
int queueSize(){
  return rear+1;
}
int queue(int value){
  if(rear+1 > currCapacity-1){
    if(currCapacity == 0){
      printf("Initialize queue array \n");
      currCapacity = initiaSize;
      queueArray = (int *)malloc(sizeof(int) * currCapacity);
    } else {
      printf("Capacity reached, doubling array now \n");
      int *newQueueArray = (int *)malloc(sizeof(int) * currCapacity * 2);
      for(int i=0; i<currCapacity; i++)
        newQueueArray[i] = queueArray[i];
      free(queueArray);
      queueArray = newQueueArray;
      currCapacity *= 2;
    }
  }
  queueArray[++rear] = value;
  return rear+1;
}
int dequeue(){
  if(rear < 0)
    return -1;
  int removed = queueArray[0];
  for(int i=0; i<rear; i++)
    queueArray[i] = queueArray[i+1];
  rear--;
  return removed;
}
void clearQueue(){
  rear = -1;
}
void printQueue(){
  if(rear < 0){
    printf("No elements in queue to print :(\n");
    return;
  }
  printf("Queue [Size: %d] (front to back) i.e. 0 - %d:\t", queueSize(), rear);
  for(int i=0; i<=rear; i++){
    printf("%d ", queueArray[i]);
  }
  printf("\n");
}



int main(){
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
        int len = queue(el);
        printf("Number added to queue, updated size of queue: %d\n", len);
        printQueue();
        break;
      case 2:
        printf("Dequeued: %d\n", dequeue());
        printQueue();
        break;
      case 3:
        printf("Front: %d, back: %d, size: %d, max capacity: %d\n", front(), back(), queueSize(), currCapacity);
        printQueue();
        break;
      case 4:
        printQueue();
        break;
      case 5:
        clearQueue();
        printQueue();
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