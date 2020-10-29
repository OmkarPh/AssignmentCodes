//Write a program for insertion and deletion of an element in an Array at given position.
#include<stdio.h>
#define capacity 20
void display(int arr[], int size){
}
void insert(int arr[], int actualSize, int ele){

}
void delete(int arr[], int actualSize, int pos){

}
void main(){
    int array[capacity];
    int size, choice;
    int el, position;
    printf("Enter no. of elements to be stored in array: ");
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        printf("Enter element no.%d: ",i+1);
        scanf("%d",&array[i]);
    }
    while (choice!=5)
    {
        printf("1. Display array\t");
        printf("2. Insert element in array\t");
        printf("3. Delete element from array\t");
        printf("4. Show size of array\t");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(size==0){
                printf("Empty array \n");
            }
            else{
                printf("Array:\t");
                for(int i=0; i<size; i++)
                    printf("%d\t",array[i]);
                printf("\n");
            }
            break;
        case 2:
            if(size==capacity-1){
                printf("Array is full!\n");
            } 
            else{
                printf("Enter the element to add: ");
                scanf("%d",&el);
                printf("Enter position where element is to be added: ");
                scanf("%d",&position);
                if(position>size+1){
                    printf("invalid position!\n");
                    break;
                }
                for(int i=size; i>=position; i--){
                    array[i] = array[i-1];
                }
                array[position-1]=el;
                size++;
                printf("Successfully inserted :)\n");
            }
            break;
        case 3:
            if(size==0){
                printf("Empty array!\n");
            }
            else{
                printf("Enter position of element is to be deleted: ");
                scanf("%d",&position);
                if(position>size){
                    printf("invalid!\n");
                    break;
                }
                for(int i=position-1; i<size-1; i++){
                    array[i] = array[i+1];
                }
                size--;
                printf("Successfully deleted :)\n");
            }
            break;
        case 4:
            printf("Size: %d\n",size);
            break;
        case 5:
            printf("Bye\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    

}