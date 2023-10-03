#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


void pidPrinter(const char *fs, ...){
    va_list vars;
    // printf("PID[%d] | ", getpid());
    printf(fs, vars);
}

void pidPrefix(){
    printf("PID[%d] | ", getpid());
}

int main() {
    // for(int i=0; i<2; i++){
    //     int forked = fork();
    //     // cout << "Forked: " << forked << endl;
        
    //     if(forked == 0){
    //         pidPrefix();
    //         printf("Parent (%d)  ->   son (%d)\n", getppid(), getpid());
    //         exit(0);
    //     }
    //     // cout << "//// ------------------------ ////\n";
    // }

    int counter = 0;

    for(int i=0; i<2; i++){
        counter += pow(2, 2-i);
        int res = fork();
        wait(NULL);
        counter += pow(2, 2-i);
        int res2 = fork();
        wait(NULL);
    }
    
    printf("Parent: %d\tMe: %d\n", getppid(), getpid());
    // printf("[%d] | OP\n", counter);

  
  return 0;
}
