#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FOR_LOOP_i_FROM_0_to_100 for(int i=0; i<=100; i+=10)


int f1_n(int n){
  return n;
}
int f2_n_cube(int n){
  return n*n*n;
}
double f3_3_by_2_pow_n(int n){
  return pow(1.5, n);
}
double f4_ln_n(int n){
  return log(n);
}
double f5_ln_ln_n(int n){
  return log(log(n));
}
double f6_log2_n(int n){
  return log2(n);
}
double f7_log2_log2_n(int n){
  return log2(log2(n));
}
double f8_n_log2_n(int n){
  return n * log2(n);
}
long f9_2_pow_n(int n){
  return pow(2, n);
}
double f10_2_pow_log_n(int n){
  return pow(2, log2(n));
}
long f11_n_fact(long n){
  return ((n == 1 || n == 0) ? 1 : n * f11_n_fact(n - 1));
}

int main(){
  printf("\n");
  printf("1. Fn: n\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %d\n", i, f1_n(i));
  printf("---------------------------------------------\n\n\n");

  printf("2. Fn: n^3\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %d\n", i, f2_n_cube(i));
  printf("---------------------------------------------\n\n\n");

  printf("3. Fn: (3/2)^n\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %.3f\n", i, f3_3_by_2_pow_n(i));
  printf("---------------------------------------------\n\n\n");

  printf("4. Fn: ln n\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %.3f\n", i, f4_ln_n(i));
  printf("---------------------------------------------\n\n\n");

  printf("5. Fn: ln ln n\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %.3f\n", i, f5_ln_ln_n(i));
  printf("---------------------------------------------\n\n\n");

  printf("6. Fn: log n\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %.3f\n", i, f6_log2_n(i));
  printf("---------------------------------------------\n\n\n");

  printf("7. Fn: log log n\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %.3f\n", i, f7_log2_log2_n(i));
  printf("---------------------------------------------\n\n\n");

  printf("8. Fn: n log n\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %.3f\n", i, f8_n_log2_n(i));
  printf("---------------------------------------------\n\n\n");

  printf("9. Fn: 2 ^ n\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %ld\n", i, f9_2_pow_n(i));
  printf("---------------------------------------------\n\n\n");

  printf("10. Fn: 2 ^ (log n)\n");
  printf("n \t Output\n\n");
  FOR_LOOP_i_FROM_0_to_100
    printf("%d \t %.3f\n", i, f10_2_pow_log_n(i));
  printf("---------------------------------------------\n\n\n");
  

  printf("11. Fn: n!\n");
  printf("n \t Output\n\n");
  for(int i=0; i<=10; i++)
    printf("%d \t %ld\n", i, f11_n_fact(i));
  printf("---------------------------------------------\n\n\n");
  

  printf("\n");
  return 0;
}