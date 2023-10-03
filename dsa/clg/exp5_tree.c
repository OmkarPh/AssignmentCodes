#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;


typedef struct Queue {
  Node **queueArray;
  int currCapacity, rear;
} Queue;
Queue* createQueue(){
  const int initiaSize = 20;
  Queue* q = (Queue*)malloc(sizeof(Queue));
  // printf("Initialize queue array \n");
  q->queueArray = (Node**)malloc(sizeof(Node*) * initiaSize);
  q->currCapacity = initiaSize;
  q->rear = -1;
  return q;
}

Node* front(Queue *q){
  return q->rear > -1 ? q->queueArray[0] : NULL;
}
Node* back(Queue *q){
  return q->rear > -1 ? q->queueArray[q->rear] : NULL;
}
int queueSize(Queue *q){
  return q->rear+1;
}
int queueEl(Queue *q, Node* value){
  if(q->rear+1 > q->currCapacity-1){
    // printf("Capacity reached, doubling array now \n");
    Node **newQueueArray = (Node**)malloc(sizeof(Node*) * q->currCapacity * 2);
    for(int i=0; i<q->currCapacity; i++)
      newQueueArray[i] = q->queueArray[i];
    free(q->queueArray);
    q->queueArray = newQueueArray;
    q->currCapacity *= 2;
  }
  q->rear++;
  q->queueArray[q->rear] = value;
  return q->rear+1;
}
Node* dequeue(Queue *q){
  if(q->rear < 0)
    return NULL;
  Node* removed = q->queueArray[0];
  for(int i=0; i<q->rear; i++)
    q->queueArray[i] = q->queueArray[i+1];
  q->rear--;
  return removed;
}
void clearQueue(Queue *q){
  q->rear = -1;
}
void printQueue(Queue *q){
  if(q->rear < 0){
    printf("No elements in queue to print :(\n");
    return;
  }
  printf("Queue [Size: %d] (front to back) i.e. 0 - %d:\t", queueSize(q), q->rear);
  for(int i=0; i<=q->rear; i++){
    printf("%d ", q->queueArray[i]->data);
  }
  printf("\n");
}


Node* createNode(int data){
  Node *newNode = (Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void preorder(Node* root){
  if(root == NULL)
      return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node* root){
  if(root == NULL)
      return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}


void postorder(Node* root){
  if(root == NULL)
      return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

void levelOrder(Node* root){
  if(root == NULL){
    printf("Empty tree !\n");
    return;
  }
  Queue* q = createQueue();
  queueEl(q, root);

  while(queueSize(q) > 0){
    Node* currNode = dequeue(q);
    printf("%d ", currNode->data);
    if(currNode->left)
      queueEl(q, currNode->left);
    if(currNode->right)
      queueEl(q, currNode->right);
  }
}

void printInternalNodes(Node* root){
  if(root == NULL){
    printf("Empty tree !\n");
    return;
  }
  Queue* q = createQueue();
  queueEl(q, root);

  while(queueSize(q) > 0){
    Node* currNode = dequeue(q);
    if(currNode->left == NULL && currNode->right == NULL)
      continue;
    printf("%d ", currNode->data);
    if(currNode->left)
      queueEl(q, currNode->left);
    if(currNode->right)
      queueEl(q, currNode->right);
  }
}
void printLeafNodes(Node* root){
  if(root == NULL){
    printf("Empty tree !\n");
    return;
  }
  Queue* q = createQueue();
  queueEl(q, root);

  while(queueSize(q) > 0){
    Node* currNode = dequeue(q);
    if(currNode->left == NULL && currNode->right == NULL)
      printf("%d ", currNode->data);
    if(currNode->left)
      queueEl(q, currNode->left);
    if(currNode->right)
      queueEl(q, currNode->right);
  }
}

int max(int a, int b){
  return a > b ? a : b;
}
int height(Node* root){
  if(root == NULL)
    return -1;
      
  int lHeight = height(root->left);
  int rHeight = height(root->right);
  
  return max(lHeight, rHeight) + 1;
}

void addNodeToTree(Node* root){
  int l, r;
  printf("Enter left node of %d (enter -1 for NULL): ", root->data);
  scanf("%d", &l);
  printf("Enter right node of %d (enter -1 for NULL): ", root->data);
  scanf("%d", &r);
  if(l != -1)
    root->left = createNode(l);
  if(r != -1)
    root->right = createNode(r);

  if(l != -1)
    addNodeToTree(root->left);  
  if(r != -1)
    addNodeToTree(root->right);
}

int main()
{
  /* Testcase:
  12
  5 42 4 8 -1 -1 6 -1 -1 -1 22 58 18 25 -1 -1 -1 -1 -1 -1
  
  Height of tree: 3
  Preorder of tree: 12 5 4 8 6 42 22 18 25 58 
  Inorder of tree: 4 5 6 8 12 18 22 25 42 58 
  Postorder of tree: 4 6 8 5 18 25 22 58 42 12 
  Level order traversal: 12 5 42 4 8 22 58 6 18 25

  */

  int rootNodeData;
  printf("Enter root node: ");
  scanf("%d", &rootNodeData);

  Node* root = createNode(rootNodeData);
  addNodeToTree(root);

  printf("\nTree created successfuly !\n");

  
  printf("\n\nHeight of tree: %d", height(root));
  printf("\n\nPreorder of tree: ");
  preorder(root);
  printf("\nInorder of tree: ");
  inorder(root);
  printf("\nPostorder of tree: ");
  postorder(root);
  printf("\n\nLevel order traversal: ");
  levelOrder(root);
  printf("\n\nInternal nodes of tree: ");
  printInternalNodes(root);
  printf("\nLeaf nodes of tree: ");
  printLeafNodes(root);

  printf("\n");
  return 0;
}