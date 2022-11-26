#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stack[400];
int sp = -1;

int size(){
  return sp+1;
}
int peek(){
  return sp > -1 ? stack[sp] : -1;
}
int push(int value){
  stack[++sp] = value; 
  return sp+1;
}
int pop(){
  if(sp < 0)
    return -1;
  sp--;
  return stack[sp+1];
}
void clearStack(){
  sp = -1;
}
void printStack(){
  if(sp < 0){
    printf("No elements in stack to print :(\n");
    return;
  }
  printf("Stack [Size: %d] (peak to bottom): ", sp+1);
  for(int i=sp; i>-1; i--){
    printf("%d ", stack[i]);
  }
  printf("\n");
}


int main(){
  int choice, el;
  while(true){
    printf("\n");
    printf("1. Push\t\t");
    printf("2. Pop\t\t");
    printf("3. Peek \t");
    printf("4. Print entire stack \t\t");
    printf("5. Clear stack \t\t");
    printf("6. Exit \n");
    printf("Your choice: ");
    int inputRes = scanf("%d", &choice);
    if(inputRes != 1){
      printf("Something's not right here, I expected a number, Did you enter something else by mistake ...? \n");
      while ((choice = getchar()) != '\n' && choice != EOF);
    }
    switch(choice){
      case 1:
        printf("Enter the element to push: ");
        scanf("%d",&el);
        int len = push(el);
        printf("Pushed onto stack, updated size of stack: %d\n", len);
        printStack();
        break;
      case 2:
        printf("Popped element: %d\n", pop());
        printStack();
        break;
      case 3:
        printf("Peak of stack: %d, size of stack: %d\n", peek(), size());
        printStack();
        break;
      case 4:
        printStack();
        break;
      case 5:
        clearStack();
        printStack();
        break;
      case 6:
        return 0;
      default:
        printf("Invalid choice opted! Try again \n");
        break;
    }
  }

  printf("\n");
  return 0;
}