#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
  char data;
  struct Node* left;
  struct Node* right;
} Node;
Node* createNode(char data){
  Node *newNode = (Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}


// Stack library
typedef struct Stack{
  Node **stack;
  int sp;
} Stack;

Stack* createStack(){
  Stack *newStack = (Stack*)malloc(sizeof(Stack));
  newStack->sp = -1;
  newStack->stack = (Node**)malloc(sizeof(Node*) * 200);
  return newStack;
}

int stackSize(Stack* stack){
  return stack->sp+1;
}
Node* peek(Stack* stack){
  return stack->sp > -1 ? stack->stack[stack->sp] : NULL;
}
int push(Node* value, Stack* stack){
  stack->stack[++(stack->sp)] = value; 
  return stack->sp+1;
}
Node* pop(Stack* stack){
  if(stack->sp < 0)
    return NULL;
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
    printf("%c ", stack->stack[i]->data);
  }
  printf("\n");
}


bool isOperand(char ch){
  return( ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}
bool isOperator(char ch){
  return( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
}
bool isCharOperand(char ch){
  return( ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}



void preorderTraversal(Node* root){
  if(root == NULL)
      return;
  printf("%c ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inorderTraversal(Node* root){
  if(root == NULL)
      return;
  inorderTraversal(root->left);
  printf("%c ", root->data);
  inorderTraversal(root->right);
}


void postorderTraversal(Node* root){
  if(root == NULL)
      return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%c ", root->data);
}


Node* createExpTree(char* str, int length){
  if(length == 0)
    return NULL;
  
  Stack* st = createStack();
  
  for(int i=0; i<length; i++){
    char curr = str[i];
    Node* currNode = createNode(curr);
    if(isOperand(curr)){
      push(currNode, st);
      printf("Created leaf node: %c\n", curr);
    } else {
      currNode->right = pop(st);
      currNode->left = pop(st);
      printf(
        "Created node: %c with left: %c, right: %c\n",
         currNode->data, currNode->left ? currNode->left->data : '-', currNode->right ? currNode->right->data : '-'
      );
      push(currNode, st);
    }
  }

  return pop(st);
}

char* evaluateExpressionAsString(Node* root){
  if(root == NULL)
    return "";
  char* left = root->left ? evaluateExpressionAsString(root->left) : "";
  char* right = root->right ? evaluateExpressionAsString(root->right) : "";

  // printf("Evaluate: (left)%s %c (right)%s\n", left, root->data, right);
  char* result = (char*)malloc(sizeof(char) * 50);
  if(strlen(left))
    strcat(result, left);
  strncat(result, &root->data, 1);
  if(strlen(right))
    strcat(result, right);
  return result;
}
double evaluateExpression(Node* root){
  if(root == NULL)
    return 0;
  if(isOperand(root->data))
    return root->data - '0';
  
  double DEFAULT_VALUE = root->data == '+' || root->data == '-' ? 0 : 1;
  double left = root->left ? evaluateExpression(root->left) : DEFAULT_VALUE;
  double right = root->right ? evaluateExpression(root->right) : DEFAULT_VALUE;
  double result = DEFAULT_VALUE;

  switch(root->data){
    case '+':
      result = left + right;
      break;
    case '-':
      result = left - right;
      break;
    case '*':
      result = left * right;
      break;
    case '/':
      result = left / right;
      break;
    default:
      result = DEFAULT_VALUE;
      break;
  }

  printf("Evaluate: (L) %.2f %c %.2f (R) = %.2f\n", left, root->data, right, result);

  return result;
}

int main(){
  /* Testcase
  abc*+def+*+
  Output - a+(b*c)+d*(e+f)

  23*21-/541-*+
  Output - 2*3/(2-1)+5*(4-1)  =  21

  ab*c/ef/g*+k+xy*-
  Output - 
  */
  char postorderInput[50];
  printf("Enter postorder expression: ");
  scanf("%s", postorderInput);

  printf("\nCreating expression tree from entered Postorder expression ........\n");
  Node* root = createExpTree(postorderInput, strlen(postorderInput));
  printf("Expression tree created succesfuly !!\n\n");

  printf("Resultant tree preorder: ");
  preorderTraversal(root);
  printf("\n");
  printf("Resultant tree inorder: ");
  inorderTraversal(root);
  printf("\n");
  printf("Resultant tree postorder: ");
  postorderTraversal(root);
  printf("\n\n");

  bool hasChar = false;
  for(int i=0; i<strlen(postorderInput); i++){
    if(isCharOperand(postorderInput[i])){
      hasChar = true;
      break;
    }
  }

  if(hasChar){
    char *result = evaluateExpressionAsString(root);
    printf("\nFinal Evaluation: %s\n", result);
  } else {
    double result = evaluateExpression(root);
    printf("\nEvaluation: %.2f\n", result);
  }


  printf("\n");
  return 0;
}