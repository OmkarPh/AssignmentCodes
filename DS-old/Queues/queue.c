#include<stdio.h>
#define size 4
int queue[size];
int front = -1, rear = -1;
void queueEl(int element){
    if(rear==size-1 || front>rear)
        printf("Queue is already full\n");
    else if(front==-1 && rear==-1){
            front++;
            rear++;
            queue[rear] = element;
           printf("Successfully Queued\n");
        } 
        else{
            rear++;
            queue[rear]=element;
           printf("Successfully Queued\n");
         }
}
void dequeue(){
    if(( front==-1 && rear==-1 ) || front>rear){
        printf("There are no elements in the queue to dequeue\n");
    }
    else{
        printf("Successfully deQueued: %d\n", queue[front]);
        front++;
    }
}
void display(){
    if(( front==-1 && rear==-1 ) || front>rear){
        printf("Empty queue\n");
    }
    else{
        int traverse = front;
        printf("Queue:\t");
        while (traverse<=rear){
            printf("%d\t",queue[traverse]);
            traverse++;
        }
        printf("\nEnd\n");
    }
}
int main(){
    int choice, el;
    while (1){
        printf("1. Queue\t");
        printf("2. DeQueue\t");
        printf("3. Display queue \t");
        printf("4. Exit \n");
        printf("Your choice: ");
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
            return 1;
            break;
        default:
            printf("Invalid choice opted! \n");
            break;
        }

    }
    return 0;
}