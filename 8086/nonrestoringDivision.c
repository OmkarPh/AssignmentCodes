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
int arithmeticLeftShift(int *a, int *b, int bits){
  int extra = a[0];

  int i=0;
  for (i=0; i < bits-1; i++)
    a[i] = a[i+1];
  
  a[i] = b[0];

  for(i=0; i<bits-1; i++)
    b[i] = b[i+1];

  return extra;
}
void printStatus(int *a, int *b, char* remark, int bits){
  printBinaryArr(a, bits);
  printf("\t\t");
  printBinaryArr(b, bits);
  printf("\t\t");
  printf("%s", remark);
  printf("\n");
}


void divideNonRestoring(int *accumulator, int *dividend, int *divisor, int bits){
  printf("Non restoring division:\n");

  int dividendSign = 3, divisorSign = 2;
  if(dividend[0] == 1){
    dividendSign = -4;
    twosComplement(dividend, bits);
  }
  if(divisor[0] == 1){
    divisorSign = -5;
    twosComplement(divisor, bits);
  }
  bool isQuotientNegative = dividendSign * divisorSign < 0;
  bool isRemainderNegative = dividendSign < 0;

  int *subDivisor = twosComplement(copyArr(divisor, bits), bits);

  printf("Add Divisor: %s", binaryArrToStr(divisor, bits));
  printf("\nSubtract Divisor: %s", binaryArrToStr(subDivisor, bits));
  printf("\n\n");

  printf("Accumulator\tDividend\tRemark\n");
  printStatus(accumulator, dividend, "Initialize", bits);
  printf("----------------------------------------------------------------------------\n");

  for(int i=0; i<bits; i++){
    int *toAdd = subDivisor;
    char *remark = "Sub M";
    if(accumulator[0] == 1){
      toAdd = divisor;
      remark = "Add M";
    }

    arithmeticLeftShift(accumulator, dividend, bits);
    printStatus(accumulator, dividend, "LS", bits);

    add(accumulator, toAdd, 0, bits);
    dividend[bits-1] = accumulator[0] == 1 ? 0 : 1;
    printStatus(accumulator, dividend, remark, bits);
    printf("----------------------------------------------------------------------------\n");
  }

  if(accumulator[0] == 1){
    add(accumulator, divisor, 0, bits);
    dividend[bits-1] = 0;
    printStatus(accumulator, dividend, "Restoration", bits);
    printf("----------------------------------------------------------------------------\n");
  }

  if(isQuotientNegative)
    twosComplement(dividend, bits);
  if(isRemainderNegative)
    twosComplement(accumulator, bits);
  if(isQuotientNegative || isRemainderNegative){
    printStatus(accumulator, dividend, "Sign adjustment", bits);
    printf("----------------------------------------------------------------------------\n");
  }
}


int main(){
  int a, b;
  printf("Enter Dividend: ");
  scanf("%d", &a);
  printf("Enter Divisor: ");
  scanf("%d", &b);

  // int a = 7, b = 3;
  // int a = -7, b = -3;
  // int a = 7, b = -3;
  // int a = -7, b = 3;

  int bits = max(calcBits(a), calcBits(b));
  printf("Bits required for dividend & divisor each: %d\n", bits);
  printf("Bits required for remainder & quotient each: %d\n\n", bits*2);

  int *accumulator = generateBinaryArrFromNum(0, bits);
  int *dividend = generateBinaryArrFromNum(a, bits); 
  int *divisor = generateBinaryArrFromNum(b, bits);

  printf("Accumulator\tDividend\tDivisor\n");
  printBinaryArr(accumulator, bits);
  printf("\t\t");
  printBinaryArr(dividend, bits);
  printf("\t\t");
  printBinaryArr(divisor, bits);
  printf("\n\n");

  divideNonRestoring(accumulator, dividend, divisor, bits);

  int quotient = decimalFromBinaryArr(dividend, bits);
  int remainder = decimalFromBinaryArr(accumulator, bits);

  printf(
    "Remainder: %s (%d),  Quotient: %s (%d)\n",
    binaryArrToStr(accumulator, bits), remainder,
    binaryArrToStr(dividend, bits), quotient
  );

  printf(
    "i.e. %d (%s)  /  %d (%s)  =  %d (%s) with remainder %d (%s)",
    a,
    binaryArrToStr(generateBinaryArrFromNum(a, bits), bits),
    b,
    binaryArrToStr(divisor, bits),
    quotient,
    binaryArrToStr(dividend, bits),
    remainder,
    binaryArrToStr(accumulator, bits)
  );

  printf("\n");


  return 0;
}
