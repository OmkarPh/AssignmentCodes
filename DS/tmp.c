#include<stdio.h>
void change(int *p){
    *p=*p+30;
}
void main(){
    char *p;
    char str[] = "MS BTE";
    p = str;
    p=p+2;
    printf("%s",++p);
    
}