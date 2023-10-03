#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char ch;  
    // rints = fopen("file_handle.c","r") ;  
    
    for(int i=0; i<10; i++){
        printf("%d\n", rand());
    }

    return 0;
}