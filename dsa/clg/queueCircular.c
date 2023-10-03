#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define queueCapacity 5
int queueArray[queueCapacity];
int fp = -1, rp = -1;

int front(){
  return fp > -1 ? queueArray[fp] : -1;
}
int back(){
  return rp > -1 ? queueArray[rp] : -1;
}
int size(){
  if(fp == -1 || rp == -1)
    return 0;
  return rp < fp ? rp + queueCapacity-fp + 1 : rp - fp + 1;
}
bool isFull(){
  return (rp+1)%queueCapacity == fp;
}
bool isEmpty(){
  return fp == -1 && rp == -1;
}
int queue(int value){
  if(isFull()){
    printf("Queue is full !! \n");
    return -1;
  }
  rp = (rp+1) % queueCapacity;
  queueArray[rp] = value;
  if(fp == -1)
    fp = 0;
  return size();
}
int dequeue(){
  if(fp == rp){
    int removed = queueArray[fp];
    fp = rp = -1;
    return removed;
  }
  fp = (fp+1)%queueCapacity;
  return queueArray[fp];
}
void clearQueue(){
  fp = rp = -1;
}
void printQueue(){
  if(isEmpty()){
    printf("No elements in queue to print :(\n");
    return;
  }

  printf("Queue [Size: %d] (front to back) i.e. %d - %d:\t", size(), fp, rp);
  int i;
  for(i=fp; i != rp; i = (i+1)%queueCapacity){
    printf("%d ", queueArray[i]);
  }
  printf("%d ", queueArray[i]);
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
        if(len != -1)
          printf("Number added to queue, updated size of queue: %d\n", len);
        printQueue();
        break;
      case 2:
        printf("Dequeued: %d\n", dequeue());
        printQueue();
        break;
      case 3:
        printf("Front: %d, back: %d, size: %d, max capacity: %d\n", front(), back(), size(), queueCapacity);
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