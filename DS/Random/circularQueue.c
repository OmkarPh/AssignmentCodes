#include<stdio.h>
#define size 4
int queue[size];
int front = -1, rear = -1;

void queueEl(int element){
    if(rear==size-1 && front==0)
        printf("Queue is already full\n");
    else if(front==-1 && rear==-1){
            front++;
            rear++;
            queue[rear] = element;
           printf("Successfully Queued\n");
        } 
        else if(rear == size-1){
                rear = 0;
                queue[rear] = element;
            }
            else{
                rear++;
                queue[rear] = element;
            }
}

void dequeue(){
    int del;
    if(( front==-1 && rear==-1 ) ){
        printf("There are no elements in the queue to dequeue\n");
    }
    else{
        if(front==rear){
            del = queue[front];
            front = -1;
            rear = -1;
        }
        else if(front==size-1){
            del = queue[front];
            front=0;
        }
        else{
            del=queue[front];
            front++;
        }
        printf("Successfully deQueued: %d\n", del);
    }
}

void display(){
    int traverse;
    if(( front==-1 && rear==-1 )){
        printf("Empty queue\n");
    }
    else if(front<=rear){
            traverse = front;
            printf("Queue:\t");
            for(int i=front; i<=rear; i++)
                printf("%d\t",queue[i]);
        } 
        else{
            printf("Queue:\t");
            for(int i=front; i<size; i++)
                printf("%d\t",queue[i]);
            for(int i=0; i<=rear; i++)
                printf("%d\t",queue[i]);
            
        }
        printf("\nEnd\n");
    
}

int main(){
    int choice, el;
    while (1){
        printf("1. Queue\n");
        printf("2. DeQueue \n");
        printf("3. Display queue \n");
        printf("4. No of elements \n");
        printf("5. Exit \n");
        printf("Your choice: \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to queue: ");
            scanf("%d",&el);
            queueEl(el);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            
            break;
        case 5:
            return 1;
            break;
        
        default:
            printf("Invalid choice opted! \n");
            break;
        }

    }
    return 0;
}