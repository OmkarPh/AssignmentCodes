#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Util
int max(int a, int b){
  return a>b ? a : b;
}
int* copyArr(int *arr, int n){
  int *copy = (int*)malloc(sizeof(int) * n);
  for(int i=0; i<n; i++)
    copy[i] = arr[i];
  return copy;
}
int* combineBytes(int *higher, int bitsHigher, int *lower, int bitsLower){
  int totalBits = bitsHigher+bitsLower;
  int *copy = (int*)malloc(sizeof(int) * totalBits);
  for(int i=0; i<bitsHigher; i++)
    copy[i] = higher[i];
  for(int i=0; i<bitsLower; i++)
    copy[i+bitsHigher] = lower[i];
  return copy;
}
int invertBit(int a){
  return a == 0 ? 1 : 0;
}
int calcBits(int a){
  // 1 extra bit for sign
  int bits=1;
  while(a != 0){
    a = a/2;
    bits++;
  }
  return bits;
}
int* twosComplement(int *num, int bits){
  int carry = 1;
  for(int i=bits-1; i>-1; i--){
    num[i] = invertBit(num[i]);
    if(carry == 1){
      carry = num[i] == 1 ? 1 : 0;
      num[i] = num[i] == 1 ? 0 : 1;
    } else {
      carry = 0;
    }
  }
  return num;
}
void printBinaryArr(int *arr, int bits){
  for(int i=0; i<bits; i++){
    printf("%d", arr[i]);
  }
}
int decimalFromBinaryArr(int *arr, int bits){
  bool isNegative = false;
  if(arr[0] == 1){
    isNegative = true;
    twosComplement(arr, bits);
  }
  int num = 0, factor = 1;
  int n = bits;
  while(n-- > 0){
    num += arr[n] * factor;
    factor *= 2;
  }

  printf("\n");
  if(isNegative)
    twosComplement(arr, bits);
  return isNegative ? -num : num;
}
int* generateBinaryArrFromNum(int num, int bits){
  bool isNegative = num < 0;
  if(num < 0)
    num = -num;
  int *binary = (int*)malloc(sizeof(int)*bits);
  int i=bits-1;
  int carry = 1;
  while(i > 0){
    // printf("i: %d, bit: %d\n", i, num/2);
    binary[i] = num % 2;

    if(isNegative){
      binary[i] = invertBit(binary[i]);
      if(carry == 1){
        carry = binary[i] == 1 ? 1 : 0;
        binary[i] = binary[i] == 1 ? 0 : 1;
      } else {
        carry = 0;
      }
    }
    num = num / 2;
    i--;
  }
  binary[0] = isNegative ? 1 : 0;
  return binary;
}
char* binaryArrToStr(int *arr, int bits){
  char *str = (char*)malloc(sizeof(char) * bits);
  for(int i=0; i<bits; i++){
    str[i] = arr[i] + '0';
  }
  return str;
}
int add(int *a, int *b, int carry, int bits){
  // printf("Add - %s + %s\n", binaryArrToStr(a, bits), binaryArrToStr(b, bits));

  if(carry < 0 || carry > 1)  
    carry = 0;
  
  for(int i=bits-1; i>-1; i--){
    int resbit = a[i] + b[i] + carry;
    if(resbit == 3){
      carry = 1;
      resbit = 1;
    } else if(resbit == 2){
      carry = 1;
      resbit = 0;
    } else {
      carry = 0;
    }
    a[i] = resbit;
  }
  return carry;
}
int arithmeticRightShift(int *a, int *b, int bits){
  int extra = b[bits-1];

  for(int i=bits-1; i>0; i--)
    b[i] = b[i-1];
  b[0] = a[bits-1];

  for(int i=bits-1; i>0; i--)
    a[i] = a[i-1];

  return extra;
}
void printStatus(int *a, int *b, int qbit, char* remark, int bits){
  printBinaryArr(a, bits);
  printf("\t\t");
  printBinaryArr(b, bits);
  printf("\t\t");
  printf("%d", qbit);
  printf("\t");
  printf("%s", remark);
  printf("\n");
}

void multiply(int *accumulator, int *multiplicand, int *multiplier, int bits){
  printf("Booth's algorithm:\n");

  int *subMultiplicand = twosComplement(copyArr(multiplicand, bits), bits);
  int qbit = 0;


  printf("Add Multiplicand: %s", binaryArrToStr(multiplicand, bits));
  printf("\nSubtract Multiplicand: %s", binaryArrToStr(subMultiplicand, bits));
  printf("\n\n");

  printf("Accumulator\tMultiplier\tQ-1\tRemark\n");
  printStatus(accumulator, multiplier, qbit, "Initialize", bits);
  printf("----------------------------------------------------------------------------\n");

  for(int i=0; i<bits; i++){
    if(qbit == 0 && multiplier[bits-1] == 1){
      add(accumulator, subMultiplicand, 0, bits);
      printStatus(accumulator, multiplier, qbit, "Sub M", bits);
    }
    if(qbit == 1 && multiplier[bits-1] == 0){
      add(accumulator, multiplicand, 0, bits);
      printStatus(accumulator, multiplier, qbit, "Add M", bits);
    }
    qbit = arithmeticRightShift(accumulator, multiplier, bits);
    printStatus(accumulator, multiplier, qbit, "RS", bits);
    printf("----------------------------------------------------------------------------\n");
  }
}

int main(){
  int a, b;
  printf("Enter Multiplicand: ");
  scanf("%d", &a);
  printf("Enter Multiplier: ");
  scanf("%d", &b);

  // int a = 5, b = -7;

  int bits = max(calcBits(a), calcBits(b));
  printf("Bits required for multiplicand & multiplier: %d\n", bits);
  printf("Bits required for result: %d\n\n", bits*2);

  int *accumulator = generateBinaryArrFromNum(0, bits);
  int *multiplicand = generateBinaryArrFromNum(a, bits); 
  int *multiplier = generateBinaryArrFromNum(b, bits);

  printf("Accumulator\tMultiplier\tMultiplicand\n");
  printBinaryArr(accumulator, bits);
  printf("\t\t");
  printBinaryArr(multiplier, bits);
  printf("\t\t");
  printBinaryArr(multiplicand, bits);
  printf("\n\n");

  multiply(accumulator, multiplicand, multiplier, bits);
  int result = decimalFromBinaryArr(combineBytes(accumulator, bits, multiplier, bits), bits*2);
  printf("Result: %s %s (%d)\n", binaryArrToStr(accumulator, bits), binaryArrToStr(multiplier, bits), result);
  printf(
    "i.e. %d (%s)  *  %d (%s)  =  %d (%s %s)",
    a,
    binaryArrToStr(multiplicand, bits),
    b,
    binaryArrToStr(generateBinaryArrFromNum(b, bits), bits),
    result,
    binaryArrToStr(accumulator, bits),
    binaryArrToStr(multiplier, bits)
  );

  printf("\n");


  return 0;
}