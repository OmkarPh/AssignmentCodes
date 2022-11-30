// Convert an infix expression to postfix expression using stack.
// print contents of stack at all intermediate steps.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Stack library
typedef struct Stack{
  char *stack;
  int sp;
} Stack;

Stack* createStack(){
  Stack *newStack = (Stack*)malloc(sizeof(Stack));
  newStack->sp = -1;
  newStack->stack = (char*)malloc(sizeof(char) * 200);
  return newStack;
}

int stackSize(Stack* stack){
  return stack->sp+1;
}
int peek(Stack* stack){
  return stack->sp > -1 ? stack->stack[stack->sp] : -1;
}
int push(char value, Stack* stack){
  stack->stack[++(stack->sp)] = value; 
  return stack->sp+1;
}
char* pop(Stack* stack){
  char *tmp = "c";
  if(stack->sp < 0)
    return tmp;
  stack->sp--;
  char popped = stack->stack[stack->sp + 1];
  return &(stack->stack[stack->sp + 1]);
  // return &popped;
  // return stack->stack[stack->sp + 1];
}
void clearStack(Stack* stack){
  stack->sp = -1;
}
void printStack(Stack* stack){
  if(stack->sp < 0){
    printf("No elements in stack to print :(");
    return;
  }
  printf("Stack [Size: %d] (peak to bottom): ", stackSize(stack));
  for(int i=stack->sp; i>-1; i--){
    printf("%c ", stack->stack[i]);
  }
}




// Precedence chart - (),  ^,   %*/  ,  +-
// Associativity:  ^ is Right to Left & rest Left to Right

int isRightToLeftAssociative(char a){
  return a == '^' ? 1 : 0;
}
int weightage(char sign){
    switch (sign){
      case '(':
      case ')':
        return 0;

      case '+':
      case '-':
          return 1;

      case '*':
      case '/':
      case '%':
          return 2;
      
      case '^':
          return 3;

      default:
          return -1;
          break;
    }
}
int isOperand(char ch) 
{ 
    if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
      return 1;
    return 0; 
}

int main(){
  Stack* stack = createStack();
  char res[150];
  char str[150];

  // Testcases:
  // a-b/c*d+e
  // K+L-M*N+(O^P)*W/U/V*T+Q
  // K+L-M*N+(O^P)*W/U/V*T+Q^J^A

  // char* str = (char*) malloc(sizeof(char) * 10);
  printf("Enter infix expression: ");
  scanf("%s", str);
  printf("Infix string: %s (len: %lu)\n", str, strlen(str));

  for(int i=0; i<strlen(str); i++){
    char ch = str[i];
    printf("Got %c | \t", str[i]);
    if(isOperand(ch))
      strncat(res, &ch, 1);
    
    else {
      if(ch == '('){
        push('(', stack);
        printStack(stack);
        printf("\t\t  |   Res: %s\n", res);
        continue;
      }
      if(ch == ')'){
        while(peek(stack) != '('){
          // printf("%c ", peek(stack));
          strncat(res, pop(stack), 1);
        }
        // printf("| ");
        pop(stack);
        printStack(stack);
        printf("\t\t  |   Res: %s\n", res);
        continue;
      }

    //   if(ch == '^' && peek(stack) == '^'){
    //     strncat(res, pop(stack), 1);
    //     push(ch, stack);
    //     printStack(stack);
    //     printf("\t\t  |   Res: %s\n", res);
    //     continue;
    //   }
      
      int currWeight = weightage(ch);
      
      // TODO Add check here for ^
      while(currWeight == weightage(peek(stack)) && isRightToLeftAssociative(peek(stack))){
        strncat(res, pop(stack), 1);
      }

      // if(currWeight <= weightage(peek(stack)))
      //   printf("Pop: ");
      while(currWeight <= weightage(peek(stack))){
        // if(ch == '^' || weightage(peek(stack)) == '^')
        // printf("%c ", peek(stack));
        strncat(res, pop(stack), 1);
      }

      // printf("| ");
      push(ch, stack);
    }
    printStack(stack);
    printf("\t\t  |   Res: %s\n", res);
  }

  printf("Dumping remaining stack into result, ");
  printStack(stack);
  printf("\n");

  while(stackSize(stack) != 0)
    strncat(res, pop(stack), 1);

  
  printf("Infix: : %s\n", str);
  printf("Postfix : %s\n", res);
  // printf("Result (len: %lu): ", strlen(res));
  // for(int i=0; i<strlen(res); i++)
  //   printf("%c", res[i]);

  printf("\n");
  return 0;
}