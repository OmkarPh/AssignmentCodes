#include<stdio.h>
#include<stdlib.h>
#define COUNT 10
struct node{
    int data;
    struct node* left;
    struct node* right;
};

void display2D(struct node*root){
    
}
struct node* create(){
    int x;
    struct node* newer = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for this node:\n");
    scanf("%d",&x);
    if(x == -1)
        return NULL;
    newer->data = x;
    printf("Left node of %d:\n",x);
    newer->left = create();
    printf("Right node of %d:\n",x);
    newer->right = create();
    return newer;
}
void inorderDisplay(struct node* root){
    if(root == NULL)
        return;
    inorderDisplay(root->left);
    printf("%d\t",root->data);
    inorderDisplay(root->right);
}
int main(){
    printf("Enter -1 for negation.\n");
    struct node* tree1 = create();
    inorderDisplay(tree1);
    printf("2D tree: \n");
    display2D(tree1);

    return 0;
}