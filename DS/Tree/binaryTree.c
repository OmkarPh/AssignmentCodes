#include<stdio.h>
#include<stdlib.h>
#define COUNT 10
struct node{
    int data;
    struct node* left;
    struct node* right;
};
void display2Dactual(struct node* root,int space){      
    if(root == NULL)
        return;
    space += COUNT;
    display2Dactual(root->right,space);

    printf("\n");
    for (int i = COUNT; i < space; i++) 
        printf(" "); 

    printf("%d",root->data);
    
    if(root->left != NULL && root->right != NULL){
        for(int i=1; i<COUNT; i++)
            printf("-");
        printf("|");
    }
    display2Dactual(root->left,space);
}
void display2D(struct node*root){
    display2Dactual(root,0);
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