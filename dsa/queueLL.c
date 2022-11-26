#include <stdio.h>
#include <stdlib.h>

int front(){
  
}
int back(){
  
}
int size(){

}
int queue(int value){

}
int dequeue(){

}
void clearQueue(){

}
void printQueue(){

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
        printf("Number added to queue, updated size of stack: %d\n", len);
        printQueue();
        break;
      case 2:
        printf("Dequeued: %d", dequeue());
        printQueue();
        break;
      case 3:
        printf("Front: %d, back: %d, size: %d", front(), back(), size());
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