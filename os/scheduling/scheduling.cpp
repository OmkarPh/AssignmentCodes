#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


typedef struct {
    int pid;
    int age;
    int oxygen;
    int arrival;
    int completion;
} Patient;

int getPriority(int age){
    return (age > 60 || age < 14) ? 1 : 2;
}
Patient* preferredPatient(Patient *p1, Patient *p2){
    if(getPriority(p1->age) <= getPriority(p2->age))
        return p1;
    return p2;
}
bool needsOxygen(Patient *p){
    return p->completion == -1;
}
Patient* newPatient(int pid){
    Patient *currPatient = (Patient*)malloc(sizeof(Patient));
    currPatient->pid = pid;
    currPatient->age = 0;
    currPatient->oxygen = 0;
    currPatient->arrival = 0;
    currPatient->completion = -1;
    return currPatient;
}

int main() {
    int patientCount;   

    // patientCount = 5;   
    // int ages[] = { 61, 59, 13, 24, 30 };
    // int oxygen[] = { 4, 3, 7, 4, 2 };
    // int arrival[] = { 0, 0, 6, 11, 12 };
    
    printf("Enter no. of patients: ");
    scanf("%d", &patientCount);

    Patient **patients = (Patient**)malloc(sizeof(Patient*) * patientCount);
    
    for(int i=0; i<patientCount; i++){
        Patient *currPatient = newPatient(i+1);
        // currPatient->age = ages[i];
        // currPatient->oxygen = oxygen[i];
        // currPatient->arrival = arrival[i];

        printf("\nFor patient %d, \n", i+1);
        printf("Age: ");
        scanf("%d", &currPatient->age);

        printf("Oxygen: ");
        scanf("%d", &currPatient->oxygen);

        printf("Arrival time: ");
        scanf("%d", &currPatient->arrival);

        patients[i] = currPatient;
    }



    // Assuming sorted
    int currentTime = 0;
    int maxLimit = 10;

    bool remaining = true;
    printf("\nGantt chart:\n(0)");
    while(remaining){
        Patient *nextPatient = NULL;
        // while(nextPatient == NULL) {
            // int nearestNextTime = currentTime;

        for(int i=0; i<patientCount; i++){
            Patient *p = patients[i];
            if(p->arrival <= currentTime && needsOxygen(p)){
                if(nextPatient == NULL){
                    nextPatient = p;
                }
                else {
                    nextPatient = preferredPatient(nextPatient, p);
                }
            } else {
                
            }
        }
        
        if(nextPatient == NULL || maxLimit < 0){
            remaining = false;
            continue;
        }
        printf(" ___P%d___ (%d)", nextPatient->pid, currentTime+nextPatient->oxygen);
        currentTime += nextPatient->oxygen;
        nextPatient->completion = currentTime;
        // remaining = false;
        maxLimit--;
    }    




    printf("\n\n");
    printf("Result Table:\n");
    printf("PID \t Age \t Priority \t Oxygen \t Arrival \t Completion \t Turnaround \t Waiting \n");
    double totalTurnaroundTime = 0;
    double totalWaitingTime = 0;
    double totalCompletionTime = 0;

    for(int i=0; i<patientCount; i++){
        Patient *p = patients[i];

        int turnaround = p->completion-p->arrival;
        totalTurnaroundTime += turnaround;

        int waiting = turnaround-p->oxygen;
        totalWaitingTime += waiting;

        totalCompletionTime += p->completion;
        
        printf("P%d \t %2d \t %d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d \n", p->pid, p->age, getPriority(p->age), p->oxygen, p->arrival, p->completion, turnaround, waiting);
    }

    printf("\n");
    printf("Total complletion time: %.lf \t Avg completion time: %.2lf\n", totalCompletionTime, totalCompletionTime/patientCount);
    printf("Total turnaround time: \t%.lf \t Avg turnaround time: %.2lf\n", totalTurnaroundTime, totalTurnaroundTime/patientCount);
    printf("Total Waiting time: \t%.lf \t Avg waiting time: %.2lf\n", totalWaitingTime, totalWaitingTime/patientCount);

    printf("\nBye !!\n");
    return 0;
}