#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack library
typedef struct Stack{
  int *stack;
  int sp;
} Stack;

Stack* createStack(){
  Stack *newStack = (Stack*)malloc(sizeof(Stack));
  newStack->sp = -1;
  newStack->stack = (int*)malloc(sizeof(int) * 200);
  return newStack;
}

int stackSize(Stack* stack){
  return stack->sp+1;
}
int peek(Stack* stack){
  return stack->sp > -1 ? stack->stack[stack->sp] : -1;
}
int push(int value, Stack* stack){
  stack->stack[++(stack->sp)] = value; 
  return stack->sp+1;
}
int pop(Stack* stack){
  if(stack->sp < 0)
    return -1;
  stack->sp--;
  return stack->stack[stack->sp + 1];
}
void clearStack(Stack* stack){
  stack->sp = -1;
}
void printStack(Stack* stack){
  if(stack->sp < 0){
    printf("No elements in stack to print :(\n");
    return;
  }
  printf("Stack [Size: %d] (peak to bottom): ", stackSize(stack));
  for(int i=stack->sp; i>-1; i--){
    printf("%d ", stack->stack[i]);
  }
  printf("\n");
}


int main(){
  int choice, el;
  Stack* st = createStack();

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
        int len = push(el, st);
        printf("Pushed onto stack, updated size of stack: %d\n", len);
       printStack(st);
        break;
      case 2:
        printf("Popped element: %d\n", pop(st));
        printStack(st);
        break;
      case 3:
        printf("Peak of stack: %d\n", peek(st));
        printStack(st);
        break;
      case 4:
        printStack(st);
        break;
      case 5:
        clearStack(st);
        printf("Stack cleared, size of stack is now: %d\n", stackSize(st));
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