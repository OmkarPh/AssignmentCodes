#include <stdio.h>
#include <stdlib.h>

int queueArray[400];
int fp = -1, bp = -1;

int front(){
  return fp > -1 ? queueArray[fp] : -1;
}
int back(){
  return bp > -1 ? queueArray[bp] : -1;
}
int size(){
  if(fp == -1 || bp == -1)
    return 0;
  return bp - fp + 1;
}
int queue(int value){
  queueArray[++bp] = value;
  if(fp == -1)
    fp = 0;
  return size();
}
int dequeue(){
  int removed = queueArray[fp];
  fp++;
  if(fp > bp){
    fp = bp = -1;
  }
  return removed;
}
void clearQueue(){
  fp = bp = -1;
}
void printQueue(){
  if(fp < 0 || bp < 0){
    printf("No elements in queue to print :(\n");
    return;
  }
  printf("Queue [Size: %d] (front to back) i.e. %d - %d:\t", size(), fp, bp);
  for(int i=fp; i<=bp; i++){
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
        printf("Front: %d, back: %d, size: %d\n", front(), back(), size());
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