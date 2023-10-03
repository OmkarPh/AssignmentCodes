typedef struct ComplexNumber {
    int real, img;
} ComplexNumber;

ComplexNumber* createComplexNumber(int real, int img);

char* complexNumberToString(ComplexNumber* n);

ComplexNumber* complexAdder(ComplexNumber* a, ComplexNumber* b);

ComplexNumber* complexSub(ComplexNumber* a, ComplexNumber* b);