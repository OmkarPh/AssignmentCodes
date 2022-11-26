#include <stdio.h>
#include <stdlib.h>

struct Entry {
  int value;
  struct Entry *prev;
};
struct Entry* createEntry(int value, struct Entry* prev){
  struct Entry *newEntry = (struct Entry*)malloc(sizeof(struct Entry));
  newEntry->prev = prev;
  newEntry->value = value;
  return newEntry;
}

struct Entry* sp = NULL;
int stackSize = 0;

int size(){
  return stackSize;
}
int peek(){
  return sp != NULL ? sp->value : -1;
}
int push(int value){
  sp = createEntry(value, sp);
  return ++stackSize;
}
int pop(){
  if(sp == NULL)
    return -1;
  int poppedValue = sp->value;
  struct Entry* poppedEntry = sp;
  sp = sp->prev;
  free(poppedEntry);
  stackSize--;
  return poppedValue;
}
void clearStack(){
  struct Entry* curr;
  while(sp != NULL){
    curr = sp;
    free(curr);
    sp = sp->prev;
  }
  stackSize = 0;
}
void printStack(){
  if(sp == NULL){
    printf("No elements in stack to print :(\n");
    return;
  }
  printf("Stack [Size: %d] (peak to bottom): ", stackSize);
  struct Entry *curr = sp;
  while(curr != NULL){
    printf("%d ", curr->value);
    curr = curr->prev;
  }
  printf("\n");
}


int main(){
  int choice, el;
  while (1){
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
    switch (choice){
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