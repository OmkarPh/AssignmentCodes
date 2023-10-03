#include <stdio.h>
#include <stdlib.h>

/* Testcase
13
1 18 1 26 1 35
1 9
3 15 3 48
2 35
3 9
1 64
1 47
3 35
*/

int *hashtable;

int hash(int key, int tableSize){
  return key % tableSize;
}

void printHashTable(int tableSize){
  printf("Hash table: \n");
  for(int i=0; i<tableSize; i++)
    printf("%d\t", i);
  printf("\n");
  for(int i=0; i<tableSize; i++)
    if(hashtable[i] == -1)
      printf("--\t");
    else if(hashtable[i] == -2)
      printf("Del\t");
    else
      printf("%d\t", hashtable[i]);
  printf("\n\n");
}

int insert(int key, int tableSize){
  int currHashIndex, initialHashIndex = hash(key, tableSize);
  for(int i=0; i<tableSize; i++){
    currHashIndex = (initialHashIndex + i) % tableSize;
    if(hashtable[currHashIndex] < 0){
      hashtable[currHashIndex] = key;
      return currHashIndex;
    }
  }
  return -1;
}
int delete(int key, int tableSize){
  int currHashIndex, initialHashIndex = hash(key, tableSize);
  for(int i=0; i<tableSize; i++){
    currHashIndex = (initialHashIndex + i) % tableSize;
    // Emtpy cell
    if(hashtable[currHashIndex] == -1)
      return -1;
    // Found !!
    if(hashtable[currHashIndex] == key){
      hashtable[currHashIndex] = -2;
      return currHashIndex;
    }
    // For -2, continue to next iteration of loop
  }
  return -1;
}
int find(int key, int tableSize){
  int currHashIndex, initialHashIndex = hash(key, tableSize);
  for(int i=0; i<tableSize; i++){
    currHashIndex = (initialHashIndex + i) % tableSize;
    if(hashtable[currHashIndex] == -1)
      return -1;
    if(hashtable[currHashIndex] == key)
      return currHashIndex;
    // For -2, continue to next iteration of loop
  }
  return -1;
}

int main(){
  int tableSize;
  printf("Enter size of table: ");
  scanf("%d", &tableSize);

  hashtable = (int *)malloc(sizeof(int) * tableSize);

  // Status- Empty by default(-1), Occupied(Key), Deleted(-2)
  for(int i=0; i<tableSize; i++)
    hashtable[i] = -1;
  printf("Initial ");
  printHashTable(tableSize);

  int choice, key;
  while (1){
    printf("\n");
    printf("1. Insert \t");
    printf("2. Delete \t");
    printf("3. Find \t");
    printf("4. Print hashtable \t");
    printf("5. Exit \n");
    printf("Your choice: ");
    int inputRes = scanf("%d", &choice);
    if(inputRes != 1){
      printf("Something's not right here, I expected a number, Did you enter something else by mistake ...? \n");
      while ((choice = getchar()) != '\n' && choice != EOF);
    }

    switch (choice){
      case 1:
        printf("Enter key to insert: ");
        scanf("%d", &key);
        int insertPosition = insert(key, tableSize);
        if(insertPosition == -1)
          printf("Element couldn't be inserted :(\n");
        else
          printf("Element inserted @ idx %d\n", insertPosition);
        printHashTable(tableSize);
        break;
      case 2:
        printf("Enter key to delete: ");
        scanf("%d", &key);
        int deletePosition = delete(key, tableSize);
        if(deletePosition == -1)
          printf("Element isn't in the hashtable\n");
        else
          printf("Element deleted from idx %d\n", deletePosition);
        printHashTable(tableSize);
        break;
      case 3:
        printf("Enter key to find: ");
        scanf("%d", &key);
        int foundPosition = find(key, tableSize);
        if(foundPosition == -1)
          printf("Element not found in the hashtable\n");
        else
          printf("Element found @ idx %d\n", foundPosition);
        printHashTable(tableSize);
        break;
      case 4:
        printHashTable(tableSize);
        break;
      case 5:
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