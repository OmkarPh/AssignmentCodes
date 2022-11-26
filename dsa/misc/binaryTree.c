#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(struct Node* root){
    if(root == NULL)
        return;
    printf("%d", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d", root->value);
    inorder(root->right);
}


void postorder(struct Node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->value);
}

int max(int a, int b){
    return a > b ? a : b;
}
int height(struct Node* root){
    if(root == NULL)
        return 0;
        
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    
    return max(lHeight, rHeight) + 1;
}


struct Node* search(struct Node* root, int value){
    if(root == NULL)
        return NULL;
        
    if(root->value == value)
        return root;
        
    struct Node *foundOnLeft = search(root->left, value);
    if(foundOnLeft != NULL)
        return foundOnLeft;
        
    struct Node *foundOnRight = search(root->right, value);
    if(foundOnRight != NULL)
        return foundOnRight;
        
    return NULL;
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    root->right->left = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);
    
    printf("Root Node: %d\n", root->value);
    printf("Root -> left: %d\n", root->left->value);
    printf("Root -> right: %d\n", root->right->value);
    
    printf("\nPreorder of tree: ");
    preorder(root);
    printf("\nInorder of tree: ");
    inorder(root);
    printf("\nPostorder of tree:");
    postorder(root);
    
    printf("\n");
    printf("\nHeight of tree: %d", height(root));
    
    struct Node *found4 = search(root, 4);
    if(found4 != NULL)
        printf("\nFound 4: %d", found4->value);
    else
        printf("\n4 not found :(");
        
    struct Node *found5 = search(root, 5);
    if(found5 != NULL)
        printf("\nFound 5: %d", found5->value);
    else
        printf("\n5 not found :(");
        
    struct Node *found1 = search(root, 1);
    if(found1 != NULL)
        printf("\nFound 1: %d", found1->value);
    else
        printf("\n1 not found :(");
        
    struct Node *found23 = search(root, 23);
    if(found23 != NULL)
        printf("\nFound 23: %d", found23->value);
    else
        printf("\n23 not found :(");
        
        
    struct Node *found9 = search(root, 9);
    if(found9 != NULL)
        printf("\nFound 9: %d", found9->value);
    else
        printf("\n9 not found :(");
        
    printf("\n");
    return 0;
}
