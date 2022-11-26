#include<stdio.h>
#include<string.h>
char temp[30];
char infixExp[30]="(";
char stack[30];
int stackSize = 0;
int top = -1;
void displayStack(){
    for(int i=0; i<stackSize; i++){
        printf("%c",stack[i]);
    }
    printf(" End\n");
}
int isEmpty() 
{ 
    if(top == -1)
        return 1; 
    return 0;
} 
char peek() 
{ 
    return stack[top]; 
} 
char pop() 
{ 
    if (!isEmpty(stack)) 
        return stack[top--] ; 
    return '-1'; 
} 
void push(char op) 
{ 
    stack[++top] = op; 
} 
int isOperand(char ch) 
{ 
    if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') )
        return 1;
    return 0; 
} 
int weightage(char sign){
    switch (sign)
    {
    case '+':
    case '-':
        return 1;
        break;

    case '*':
    case '/':
    case '%':
        return 2;
        break;
    
    case '^':
        return 3;
        break;

    default:
        return -1;
        break;
    }

}
void convertToPostFix(char *infix){
    puts(infix);
    char currentChar;
    for(int i=0; i<strlen(infix); i++){
        if (isOperand(infix[i])) 
            printf("%c",infix[i]);
        else if (infix[i] == '(') 
            push(infix[i]);
        else if (infix[i] == ')') 
        { 
            while (!isEmpty() && peek() != '(') 
                printf("%c",pop()); 
                
            if (!isEmpty() && peek() != '(') {
                printf("invalid expression!\n");
                return; // invalid expression              
            }
            else
                pop(); 
        }else { 
            // an operator is encountered 
            while (!isEmpty() && weightage(infix[i]) <= weightage(peek())) 
                printf("%c",pop()); 
            push(infix[i]); 
        }  
    }
}
int main(){
    printf("Enter the infix expression: ");
    gets(temp);
    strcat(temp,")");
    // puts(temp);
    strcat(infixExp,temp);
    convertToPostFix(infixExp);
    return 0;
}
/*
array
single
doubly
stack
infix to postfix **
simple queue
circular queue
priority queue
construct tree (TRAVERSAL METHODS DFS BFS                    )
Linear and binary search
sorting methods

*/