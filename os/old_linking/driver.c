#include<stdio.h>
#include "lib_complex.h"

int main(){
    ComplexNumber *c1 = createComplexNumber(5, 2);
    ComplexNumber *c2 = createComplexNumber(3, 7);
    ComplexNumber *c3 = complexAdder(c1, c2);
    printf("C1: %s \n", complexNumberToString(c1));
    printf("C2: %s \n", complexNumberToString(c2));
    printf("C1 + C2: %s \n", complexNumberToString(c3));
    printf("C1 - C2: %s \n", complexNumberToString(complexSub(c1, c2)));

    return 0;
}