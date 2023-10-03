#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Utility
int max(int a, int b){
  return a > b ? a : b;
}
void swap(int *a, int *b){
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

typedef struct Heap{
  int *heap;
  int size, capacity;
} Heap;
void printHeapLevelWise(Heap *heap){
  printf("Heap (%d): \n", heap->size);
  int nodesinlevel = 1;
  for(int i=0; i<heap->size;){
    int levelends = i+nodesinlevel;
    for(; i < levelends; i++){
      if(i >= heap->size || heap->heap[i] == -1)
        printf("- ");
      else
        printf("%d ", heap->heap[i]);
    }
    printf("\n");
    nodesinlevel *= 2;
  }
  printf("\n");
}
Heap* createHeap(int capacity){
  capacity *= 4;
  Heap* heap = (Heap*)malloc(sizeof(Heap));
  heap->heap = (int*)malloc(sizeof(int) * capacity);
  for(int i=0; i<capacity; i++)
    heap->heap[i] = -1;
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

// void increaseHeapCapacity(Heap *heap){
//   int prevCapacity = heap->capacity;
//   heap->capacity *= 2;
//   int *tempHeapArr = (int*)malloc(sizeof(int) * heap->capacity);
//   int i=0;
//   for(; i<prevCapacity; i++)
//     tempHeapArr[i] = heap->heap[i];
//   for(; i<heap->capacity; i++)
//     tempHeapArr[i] = -1;
//   heap->heap = tempHeapArr;
// }


void heapify(int *heapArr, int n, int root){
  int l = root*2 + 1;
  int r = root*2 + 2;
  int max = root;
  if(l < n && heapArr[l] > heapArr[max])
    max = l;
  if(r < n && heapArr[r] > heapArr[max])
    max = r;
  // printf("Heapify: %d, l(%d), r(%d), got max: %d\n", heapArr[root], heapArr[l], heapArr[r], heapArr[max]);
  if(max != root){
    // printf("Swapped root: %d with %d\n", heapArr[root], heapArr[max]);
    swap(&heapArr[root], &heapArr[max]);
    heapify(heapArr, n, max);
  }
}
Heap* buildHeap(int *heapArr, int n){
  printf("Before BUILDHEAP, array (%d): ", n);
  for(int i=0; i<n; i++)
    printf("%d ", heapArr[i]);
  printf("\n");

  Heap* heap = createHeap(n);
  heap->heap = heapArr;
  heap->size = heap->capacity = n;

  // skip leaves
  for(int traveller=n/2 - 1; traveller>-1; traveller--){
    // printf("\nHeapify node: %d\n", heapArr[traveller]);
    heapify(heapArr, n, traveller);
  }

  printf("After BUILDHEAP, array (%d): ", n);
  for(int i=0; i<n; i++)
    printf("%d ", heapArr[i]);
  printf("\n");
  return heap;
}

void insertInHeap(Heap *heap, int num){
  // printf("Before insert, heap details - size(%d)\n", heap->size);
  int currPosition = heap->size;
  heap->heap[currPosition] = num;
  int parentPosition = (currPosition-1) / 2;
  while(currPosition != 0 && heap->heap[currPosition] > heap->heap[parentPosition]){
    // printf("Exchange curr(%d) & parent(%d)\n", heap->heap[currPosition], heap->heap[parentPosition]);
    swap(&heap->heap[currPosition], &heap->heap[parentPosition]);
    currPosition = parentPosition;
    parentPosition = (currPosition-1) / 2;
  }
  // printf("Inserting %d, Its parent: %d\n", num, heap->heap[parentPosition]);
  heap->size++;
  // printf("\n");
}

int deleteFromHeap(Heap* heap){
  int deleted = heap->heap[0];
  heap->size--;
  heap->heap[0] = heap->heap[heap->size];
  heap->heap[heap->size] = -1;
  
  int traveller = 0;
  int l, r, target;
  while(2*traveller+1 <= heap->size){
    l = 2*traveller + 1;
    r = 2*traveller + 2;
    if(heap->heap[l] > heap->heap[r])
      target = l;
    else
      target = r;
    if(heap->heap[target] > heap->heap[traveller])
      swap(&heap->heap[target], &heap->heap[traveller]);
    else
      break;
    traveller = target;
  }
  return deleted;
}
// @TODO
int kthLargestInHeap(Heap* heap){
  return heap->heap[0];
}
int* heapsort_(Heap* heap){
  int* heapArr = heap->heap;
  for(int i=heap->size-1; i>-1; i--){
    swap(&heapArr[0], &heapArr[i]);
    heapify(heapArr, i, 0);
  }
  return heapArr;
}

int main(){
  /* Test cases
  8
  5 12 64 1 37 90 91 97
  

  */

  int n;
  printf("Enter number of elements in sequence: ");
  scanf("%d", &n);

  printf("Enter elements in sequence: ");
  int *inputarr = (int*)malloc(sizeof(int) * n);
  for(int i=0; i<n; i++)
    scanf("%d", &inputarr[i]);
  printf("\n");

  Heap *heap = buildHeap(inputarr, n);
  printf("\n");
  printHeapLevelWise(heap);

  // // Successive insertion
  // for(int i=0; i<n; i++){
  //   insertInHeap(heap, inputarr[i]);
  //   printf("Inserted %d  \n", inputarr[i]);
  //   // printHeap(heap);
  //   printHeapLevelWise(heap);
  // }


  int choice, data;
  int *heapsortedarray;
  bool showmenu = true;
  while (showmenu){
    printf("\n");
    printf("1. Insert \t");
    printf("2. Delete node \t");
    printf("3. Get kth largest number \t");
    printf("4. Heapsort \t");
    printf("5. Print heap \t");
    printf("\nYour choice: ");
    int inputRes = scanf("%d", &choice);
    if(inputRes != 1){
      printf("Something's not right here, I expected a number, Did you enter something else by mistake ...? \n");
      while ((choice = getchar()) != '\n' && choice != EOF);
    }

    switch (choice){
      case 1:
        printf("Enter number to insert: ");
        scanf("%d", &data);
        insertInHeap(heap, data);
        printHeapLevelWise(heap);
        break;
      case 2:
        data = deleteFromHeap(heap);
        printf("Deleted %d from heap\n", data);
        printHeapLevelWise(heap);
        break;
      case 3:
        break;
      case 4:
        heapsortedarray = heapsort_(heap);
        n = heap->size;
        printf("Sorted heap (%d): ", n);
        for(int i=0; i<heap->size; i++){
          printf("%d ", heap->heap[i]);
        }
        printf("\n");
        showmenu = false;
        break;
      case 5:
        printHeapLevelWise(heap);
        break;
      default:
        printf("Invalid choice opted! Try again \n");
        break;
    }
  }


  showmenu = true;
  while (showmenu){
    printf("\n");
    printf("1. Get kth largest number \t");
    printf("2. Exit");
    printf("\nYour choice: ");
    int inputRes = scanf("%d", &choice);
    if(inputRes != 1){
      printf("Something's not right here, I expected a number, Did you enter something else by mistake ...? \n");
      while ((choice = getchar()) != '\n' && choice != EOF);
    }
    switch (choice){
      case 1:
        printf("Enter k, for kth largest element: ");
        scanf("%d", &data);
        if(data < 0 || data >= n)
          printf("Sorted heap size is %d, but %d is out of range !!!!\n", n, data);
        else
          printf("%d-th largest element: %d\n", data, heapsortedarray[n-data-1]);
        break;
      case 2:
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