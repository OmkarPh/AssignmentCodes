#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data, height;
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
  newNode->height = 0;
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
  return root->height;
}
void updateHeight(Node* root){
  root->height = max(height(root->left), height(root->right)) + 1;
}
int balance(Node* root){
  return height(root->left) - height(root->right);
}
bool isBalanced(Node* root){
  int thisBalance = balance(root);
  return thisBalance > -2 && thisBalance < 2;
}

Node* leftRotate(Node* oldRoot){
  Node* newRoot = oldRoot->right;
  oldRoot->right = newRoot->left;
  newRoot->left = oldRoot;

  updateHeight(oldRoot);
  updateHeight(newRoot);
  return newRoot;
}
Node* rightRotate(Node* oldRoot){
  Node* newRoot = oldRoot->left;
  oldRoot->left = newRoot->right;
  newRoot->right = oldRoot;

  updateHeight(oldRoot);
  updateHeight(newRoot);
  return newRoot;
}

Node* insert(Node *root, int num){
  if(root == NULL)
    return createNode(num);

  if(root->data == num){
    printf("%d already exists in tree !\n", root->data);
    return root;
  }

  if(num < root->data)
    root->left = insert(root->left, num);
  else
    root->right = insert(root->right, num);

  root->height = max(height(root->left), height(root->right)) + 1;

  int thisBalance = balance(root);

  // Left height  > Right height
  if(thisBalance > 1){
    // LL
    if(num < root->left->data){
      return rightRotate(root);
    }

    // LR
    if(num > root->left->data){
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }

  // Right height  > Left height
  if(thisBalance < -1){
    // RR
    if(num > root->right->data){
      return leftRotate(root);
    }

    // RL
    if(num < root->right->data){
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }

  return root;
}
Node* removeNode(Node *root, int num){
  return root;
}
Node* findNode(Node *root, int num){
  Node* temp = root;
  while(temp != NULL){
    if(temp->data == num)
      return temp;
    if(num < temp->data)
      temp = temp->left;
    else
      temp = temp->right;
  }
  return NULL;
}

int main()
{
  /* Testcase:
  Other ex:
  1 33 1 9 1 53 1 61 1 21 1 8 1 11
  1 13 1 10 1 15 1 5 1 11 1 16 1 4 1 6
  1 30 1 5 1 35 1 32 1 40

  PPT
  1 20 1 45 1 90 1 70 1 10 1 40 1 35 1 30 1 99 1 60 1 50 1 80
  2
  4
  
  */
  printf("AVL \n");

  Node* root = NULL;


  int choice, el;
  while (1){
    printf("\n");
    printf("1. Insert \t");
    printf("2. Display \t");
    printf("3. Search \t");
    printf("4. Exit \n");
    printf("Your choice: ");
    int inputRes = scanf("%d", &choice);
    if(inputRes != 1){
      printf("Something's not right here, I expected a number, Did you enter something else by mistake ...? \n");
      while ((choice = getchar()) != '\n' && choice != EOF);
    }

    switch (choice){
      case 1:
        printf("Enter number to insert: ");
        scanf("%d", &el);
        root = insert(root, el);
        printf("Tree: ");
        inorder(root);
        printf("\n");
        break;
      case 2:
        printf("Display:\nHeight of tree: %d", height(root));
        printf("\nPreorder of tree: ");
        preorder(root);
        printf("\nInorder of tree: ");
        inorder(root);
        printf("\nPostorder of tree: ");
        postorder(root);
        printf("\nLevel order traversal: ");
        levelOrder(root);
        // printf("\n\nInternal nodes of tree: ");
        // printInternalNodes(root);
        // printf("\nLeaf nodes of tree: ");
        // printLeafNodes(root);
        printf("\n");
        break;
      case 3:
        printf("Enter number to search: ");
        scanf("%d", &el);
        Node* searchedNode = findNode(root, el);
        if(searchedNode){
          printf("Found: Node( data: %d", searchedNode->data);
          if(searchedNode->left)
            printf(", l: %d", searchedNode->left->data);
          if(searchedNode->right)
            printf(", r: %d", searchedNode->right->data);
          printf(", h: %d, bal: %d ) \n", height(searchedNode), balance(searchedNode));
        } else
          printf("%d not found in the tree !", el);
        break;
      case 4:
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