#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "lib_complex.h"

ComplexNumber* createComplexNumber(int real, int img){
    ComplexNumber *res = (ComplexNumber *)malloc(sizeof(ComplexNumber));
    res->real = real;
    res->img = img;
    return res;
}
char* complexNumberToString(ComplexNumber* n){
    char *str = (char *)malloc(sizeof(char) * 25);
    if(n->img < 0)
        sprintf(str, "%d - %d j", n->real, -(n->img));
    else
        sprintf(str, "%d + %d j", n->real, n->img);
    return str;
}
ComplexNumber* complexAdder(ComplexNumber* a, ComplexNumber* b){
    ComplexNumber *res = (ComplexNumber *)malloc(sizeof(ComplexNumber));
    res->real = a->real + b->real;
    res->img = a->img + b->img;
    return res;
}
ComplexNumber* complexSub(ComplexNumber* a, ComplexNumber* b){
    ComplexNumber *res = (ComplexNumber *)malloc(sizeof(ComplexNumber));
    res->real = a->real - b->real;
    res->img = a->img - b->img;
    return res;
}



// int main(){
//     ComplexNumber *c1 = createComplexNumber(5, 2);
//     ComplexNumber *c2 = createComplexNumber(3, 7);
//     ComplexNumber *c3 = complexAdder(c1, c2);
//     printf("C1: %s \n", complexNumberToString(c1));
//     printf("C2: %s \n", complexNumberToString(c2));
//     printf("C1 + C2: %s \n", complexNumberToString(c3));
//     printf("C1 - C2: %s \n", complexNumberToString(complexSub(c1, c2)));
//     return 0;
// }