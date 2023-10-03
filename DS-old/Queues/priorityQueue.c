// Not complete
#include<stdio.h>
#include<stdlib.h>
int curId = 1;
char status[7][10] = {" Invalid "," General "," Ladies ","Handicap"," Senior ","  VIP  "};
struct personInQueue{
    char name[20];
    // Weightages: VIP=5, Senior =4, Handicap=3, Ladies=2, General =1
    int weightage, regId;
    struct personInQueue *next;

}*first;

void queuePerson(struct personInQueue *new){
    if(first==NULL){
        first = new;
        printf("Succesfully queued at first and only pos\n");
        return;
    }
    if(first->weightage < new->weightage){
        new->next = first;
        first = new;
        printf("Succesfully queued at first pos\n");
        return;
    }


    struct personInQueue *check = first;
    struct personInQueue *prev = first;

    while( (check!=NULL && check->weightage >= new->weightage ) ){
        //printf("Going behind of %s",check->name);
        prev = check;
        check = check->next;
    }
    new->next = prev->next;
    prev->next = new;

    printf("Succesfully queued\n");
    
}

struct personInQueue* askForDetails(){
    struct personInQueue *newEntry = (struct personInQueue*) malloc(sizeof(struct personInQueue));
    newEntry->next = NULL;
    newEntry->regId=curId++;
    printf("Enter your name: ");
    scanf("%s",&newEntry->name);

    printf("From the following: 1.General \t 2.Ladies\t 3.Handicap\t 4.Senior\t 5.VIP\n");
    printf("Choose your status: ");
    scanf("%d",&newEntry->weightage);
    if(newEntry->weightage > 5 || newEntry->weightage < 1)
        newEntry->weightage = 0;
    return newEntry;
}

void display(){
    struct personInQueue *traverse = first;
    printf("Queue of reservation priority wise: \n");
    while (traverse!=NULL){
        printf(".-----------------------.\n");
        printf("|    %s (%s)\t|\n",traverse->name,status[traverse->weightage]);
        printf("'-----------------------'\n");
        
        traverse = traverse->next;
    }
    printf("End\n");
    
}

int main(){
    int choice, el;

    while (1){
        printf("Do you want to reserve ticket for any person? Yes: 1  /  No: 0\n");
        //printf("2. DeQueue \n");
        printf("Answer: ");
        scanf("%d",&choice);
        if(choice)
            queuePerson(askForDetails());
        else
            break;
    }
    display();


    return 0;
}