#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;
typedef struct DoublyLL {
  struct Node* head;
  struct Node* tail;
} DoublyLL;

Node* createNode(int data){
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void printLinkedList(DoublyLL *ll){
  Node* head = ll->head;
  Node* tail = ll->tail;

  if(head == NULL || tail == NULL){
    printf("Empty linked list ---\n");
    return;
  }
  printf("Linked list: \n");
  printf("H-to-T: ");
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL \n");

  printf("T-to-H: ");
  while(tail != NULL){
    printf("%d -> ", tail->data);
    tail = tail->prev;
  }
  printf("NULL \n");
}

DoublyLL* insertAtLast(DoublyLL *ll, int data){
  Node* newNode = createNode(data);

  if(ll->tail == NULL){
    ll->head = newNode;
    ll->tail = newNode;
    return ll;
  }
  
  ll->tail->next = newNode;
  newNode->prev = ll->tail;
  ll->tail = newNode;
  return ll;
}

DoublyLL* insertAtPosition(DoublyLL *ll, int data, int position){
  Node* newNode = createNode(data);
  if(ll == NULL){
    ll->head = newNode;
    ll->tail = newNode;
    return ll;
  }
  if(position == 0){
    newNode->next = ll->head;
    ll->head->prev = newNode;
    ll->head = newNode;
    return ll;
  }
  Node *curr = ll->head;
  for(int i=1; i<position; i++){
    if(curr->next == NULL)
      break;
    curr = curr->next;
  }
  newNode->next = curr->next;

  if(ll->tail == curr)
    ll->tail = newNode;
  newNode->prev = curr;
  if(curr->next)
    curr->next->prev = newNode;
  curr->next = newNode;
  return ll;
}

void swapNodes(DoublyLL *list, Node *n1, Node *n2){
  if(n1 == n2)
    return;
  Node *temp = n2->prev;
  if(n1 == list->head)

  n1->prev->next = n2;
  n2->prev = n1->prev;

  n2->next = n1->next;
  n1->next->prev = n2;

  temp->next = n1;
}
void sortDoublyLL(DoublyLL *list){
  if(list->head == NULL || list->head->next == NULL)
    return;

  Node *anchor = list->head;
  Node *curr = list->head->next;
  while(anchor->next != NULL){
    curr = anchor->next;
    Node *minNode = anchor;
    while(curr != NULL){
      if(curr->data < minNode->data)
        minNode = curr;
      curr = curr->next;
    }
    // printf("For anchor %d, Min node: %d\n", anchor->data, minNode->data);
    int temp = anchor->data;
    anchor->data = minNode->data;
    minNode->data = temp;
    anchor = anchor->next;
  }
}

int main(){

  /* Testcase1
  1 23 1 82 1 4 1 20 1 53 1 6 2 55 1
  3
  1 32 1 8 1 92 1 25 2 85 3
  3


  Linked list 1: 
  H-to-T: 23 -> 55 -> 82 -> 4 -> 20 -> 53 -> 6 -> NULL 
  T-to-H:  6  -> 55 -> 20 -> 4 -> 82 -> 55 -> 23 -> NULL 
  Linked list 2: 
  H-to-T: 32 -> 8 -> 92 -> 85 -> 25 -> NULL 
  T-to-H: 25 -> 85 -> 92 -> 8 -> 32 -> NULL 
  Sorted:
  */ 
  
  DoublyLL *l1 = (DoublyLL*)malloc(sizeof(DoublyLL));
  DoublyLL *l2 = (DoublyLL*)malloc(sizeof(DoublyLL));

  DoublyLL *currLL;
  DoublyLL* allLists[] = {l1, l2};

  int choice, data, pos;
  for(int i=1; i<3; i++){
    currLL = allLists[i-1];
    printf("\nList %d ops ", i);
    printf("----------------------------------------------------------------------------------------------------------------\n");
    int showMenu = 1;
    while(showMenu){
      printf("\n");
      printf("1. Insert at end \t");
      printf("2. Insert at position \t");
      printf("3. Next \n");
      printf("Your choice: ");
      int inputRes = scanf("%d", &choice);
      if(inputRes != 1){
        printf("Something's not right here, I expected a number, Did you enter something else by mistake ...? \n");
        while ((choice = getchar()) != '\n' && choice != EOF);
      }

      switch (choice){
        case 1:
          printf("Enter element to insert: ");
          scanf("%d", &data);
          insertAtLast(currLL, data);
          printLinkedList(currLL);
          break;
        case 2:
          printf("Enter element to insert: ");
          scanf("%d", &data);
          printf("Enter position to insert: ");
          scanf("%d", &pos);
          insertAtPosition(currLL, data, pos);
          printLinkedList(currLL);
          break;
        case 3:
          showMenu = 0;
          break;
        default:
          printf("Invalid choice opted! Try again \n");
          break;
      }
    }

  }

  printf("\nBoth Doubly LL are ready: \n");
  printf("\n1. ");
  printLinkedList(l1);
  printf("\n2. ");
  printLinkedList(l2);


  sortDoublyLL(l1);
  printf("\n1. Sorted ");
  printLinkedList(l1);
  sortDoublyLL(l2);
  printf("\n2. Sorted ");
  printLinkedList(l2);

  DoublyLL* mergedLL = (DoublyLL*)malloc(sizeof(DoublyLL));
  Node* h1 = l1->head;
  Node* h2 = l2->head;

  int min;
  while(h1 != NULL && h2 != NULL){
    if(h1->data < h2->data){
      min = h1->data;
      h1 = h1->next;
    } else {
      min = h2->data;
      h2 = h2->next;
    }
    insertAtLast(mergedLL, min);
  }
  while(h1 != NULL){
    insertAtLast(mergedLL, h1->data);
    h1 = h1->next;
  }
  while(h2 != NULL){
    insertAtLast(mergedLL, h2->data);
    h2 = h2->next;
  }
  printf("\nMerged sorted ");
  printLinkedList(mergedLL);

  return 0;
}