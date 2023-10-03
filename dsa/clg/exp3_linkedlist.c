#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* createNode(int data){
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void printLinkedList(Node *head){
  if(head == NULL){
    printf("Empty linked list ---\n");
    return;
  }
  printf("Linked list: ");
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL \n");
}

Node* insertAtLast(Node *head, int data){
  Node* newNode = createNode(data);
  if(head == NULL)
    return newNode;
  Node *curr = head;
  while(curr->next != NULL)
    curr = curr->next;
  curr->next = newNode;
  return head;
}

Node* insertAtPosition(Node *head, int data, int position){
  Node* newNode = createNode(data);
  if(head == NULL)
    return newNode;
  if(position == 0){
    newNode->next = head;
    return newNode;
  }
  Node *curr = head;
  for(int i=1; i<position; i++){
    if(curr->next == NULL)
      break;
    curr = curr->next;
  }
  newNode->next = curr->next;
  curr->next = newNode;
  return head;
}

Node* deleteAtPosition(Node *head, int position){
  if(head == NULL)
    return NULL;
  Node *curr = head;
  for(int i=1; i<position; i++)
    curr = curr->next;
  if(curr->next != NULL){
    Node *tmp = curr->next;
    curr->next = curr->next->next;
    free(tmp);
  }
  return head;
}

Node* swapAdjacent(Node* head){
  if(head == NULL || head->next == NULL)
    return head;

  printf("\n----------------------------------------------------------------------------------------------------------------\n");
  printf("Original,\n");
  printLinkedList(head);

  printf("\nSteps in swapping: \n");
  Node* curr = head;
  // Swap head & next one first
  head = head->next;
  curr->next = head->next;
  head->next = curr;
  printLinkedList(head);

  Node* temp;
  while(curr->next != NULL && curr->next->next != NULL){
    temp = curr->next;
    curr->next = curr->next->next;
    temp->next = curr->next->next;
    curr->next->next = temp;
    printLinkedList(head);
    curr = temp;
  }
  printf("\nFinally, after swapping,\n");
  printLinkedList(head);
  printf("----------------------------------------------------------------------------------------------------------------\n");
  return head;
}

int main(){

  /* Testcase1
  1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 1 11 1 12 1 13 1 14
  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> 13 -> 14 -> NULL
  ------     -------     -------     -------     -------     --------       --------      ---
  2 -> 1 -> 4 -> 3 -> 6 -> 5 -> 8 -> 7 -> 10 -> 9 -> 12 -> 11 -> 14 -> 13 -> NULL

  Testcase2
  1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 1 11 1 12 1 13 1 14 1 15
  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> 13 -> 14 -> 15 -> NULL
  ------     -------     -------     -------     -------     --------       --------      ---
  2 -> 1 -> 4 -> 3 -> 6 -> 5 -> 8 -> 7 -> 10 -> 9 -> 12 -> 11 -> 14 -> 13 -> 15 -> NULL
  */ 
  

  Node* head = NULL;
  int choice, data, pos;
  while (1){
    printf("\n");
    printf("1. Insert at end \t");
    printf("2. Insert at position \t");
    printf("3. Delete at position \t");
    printf("4. Perform swap on every two adjacent nodes \t");
    printf("5. Exit \n");
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
        head = insertAtLast(head, data);
        printLinkedList(head);
        break;
      case 2:
        printf("Enter element to insert: ");
        scanf("%d", &data);
        printf("Enter position to insert: ");
        scanf("%d", &pos);
        head = insertAtPosition(head, data, pos);
        printLinkedList(head);
        break;
      case 3:
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        head = deleteAtPosition(head, pos);
        printLinkedList(head);
        break;
      case 4:
        head = swapAdjacent(head);
        break;
      case 5:
        printf("Bye !!\n");
        return 0;
      default:
        printf("Invalid choice opted! Try again \n");
        break;
    }
  }

  return 0;
}