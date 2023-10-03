#include<stdio.h>
#include<math.h>

void add(int A[], int B[],int n){                //function to add the binary number
    int carry=0,res[n+1];
    for (int i=0;i<=n;i++){
        res[i] =A[i] + B[i] + carry;
               if (res[i] >= 2){
                    carry = 1;
               }
               else{
                    carry= 0;
               }
               res[i] = res[i]%2;
    }
    for (int i=n;i>=0;i--){
        A[i]=res[i];
    }
}
void shift_left(int A[],int Q[],int n){        //function to arithmetic shift for the A, Q
    int temp=Q[n];
    for(int i=n;i>0;i--){
        Q[i]=Q[i-1];
    }
    for(int i=n;i>0;i--){
        A[i]=A[i-1];
    }
    A[0]=temp;  
}

int main(){
    int a, a1 ,b, b1, n, flag_a=0, flag_b=0, sign_a=1, sign_b=1, choice;
    printf("Enter bit-size: ");
    scanf("%d",&n);
    printf("Enter Dividend: ");
    scanf("%d", &a);                             //Dividend
    printf("Enter Divisor: ");
    scanf("%d", &b);
    n=n-1;                             //Divisor
    if(a<0){                                     //Absolute value of Dividend
        a1=abs(a);
        flag_a=1;
        sign_a=-1;
    }
    else{
        a1=a;
    }
    if(b<0){                                     //Absolute value of divisor
        b1=abs(b);
        flag_b=1;
        sign_b=-1;
    }
    else{
        b1=b;
    }
    // if (a1<=b1){                                 //bitsize
    //     n=(int)log2(b1)+2;
    // }
    // else{
    //     n=(int)log2(a1)+2;
    // }
    int M[n+1], Mcomp[n+1], Q[n+1], A[n+1], q=0;  
    for (int i=0;i<=n;i++){                       //making binary
        M[i]=b1%2;
        Q[i]=a1%2;
        A[i]=0;
        a1=a1/2;
        b1=b1/2;
    }
    int carry=1;                                  //M compliment for subtracting
    for(int i=0;i<=n;i++){
        if (M[i]==1){
            Mcomp[i]=0;
        }
        else{
            Mcomp[i]=1;
        }
    }
    for(int i=0;i<=n;i++){
        if ((Mcomp[i]==1)&&carry==1){
            Mcomp[i]=0;
        }
        else if ((Mcomp[i]==0)&&carry==1){
            Mcomp[i]=1;
            carry=0;
        }
    }
    printf("\n");
    printf("Binary form of Q: ");
    for (int i=n;i>=0;i--){
        printf("%d",Q[i]);
    }
    printf("\nBinary form of M: ");
    for (int i=n;i>=0;i--){
        printf("%d",M[i]);
    }
    printf("\nBinary form of M': ");
    for (int i=n;i>=0;i--){
        printf("%d",Mcomp[i]);
    }
    printf("\n\nEnter Your Choice\n");
    printf(" 1 for Restoring Division algorithm\n");
    printf(" 2 for Non-Restoring Division algorithm\n");
    scanf("%d",&choice);
    printf("\n\n");
    if(choice==1){                             //restoring division algorithm
        printf("******Restoring Division algorithm******\n\n");
        for (int i=0;i<=n;i++){
            shift_left(A,Q,n);
            printf("A: ");
            for (int i=n;i>=0;i--){
                printf("%d",A[i]);
            }
            printf("\t");
            printf("Q: ");
            for (int i=n;i>=0;i--){
                printf("%d",Q[i]);
            }
            printf("\tLeft Shift\n");
            add(A,Mcomp,n);
            printf("A: ");
            for (int i=n;i>=0;i--){
                printf("%d",A[i]);
            }
            printf("\t");
            printf("Q: ");
            for (int i=n;i>=0;i--){
                printf("%d",Q[i]);
            }
            printf("\tA <-- A-M\n");
            if (A[n]==1){
                Q[0]=0;
                add(A,M,n);
                printf("A: ");
                for (int i=n;i>=0;i--){
                    printf("%d",A[i]);
                }
                printf("\t");
                printf("Q: ");
                for (int i=n;i>=0;i--){
                    printf("%d",Q[i]);
                }
                printf("\tA <-- A+M & Set Q[0]=1\n");
            }
            else{
                Q[0]=1;
                printf("A: ");
                for (int i=n;i>=0;i--){
                    printf("%d",A[i]);
                }
                printf("\t");
                printf("Q: ");
                for (int i=n;i>=0;i--){
                    printf("%d",Q[i]);
                }
                printf("\tSet Q[0]=1\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    else if(choice==2){                              //non-restoring division algorithm
        printf("******Non-Restoring Division algorithm******\n\n");
        for (int i=0;i<=n;i++){
            shift_left(A,Q,n);
            printf("A: ");
            for (int i=n;i>=0;i--){
                printf("%d",A[i]);
            }
            printf("\t");
            printf("Q: ");
            for (int i=n;i>=0;i--){
                printf("%d",Q[i]);
            }
            printf("\tLeft Shift\n");
            if (A[n]==1){
                add(A,M,n);
                printf("A: ");
                for (int i=n;i>=0;i--){
                    printf("%d",A[i]);
                }
                printf("\t");
                printf("Q: ");
                for (int i=n;i>=0;i--){
                    printf("%d",Q[i]);
                }
                printf("\tA <-- A+M\n");
            }
            else{
                add(A,Mcomp,n);
                printf("A: ");
                for (int i=n;i>=0;i--){
                    printf("%d",A[i]);
                }
                printf("\t");
                printf("Q: ");
                for (int i=n;i>=0;i--){
                    printf("%d",Q[i]);
                }
                printf("\tA <-- A-M\n");
            }
            if (A[n]==1){
                Q[0]=0;
                printf("A: ");
                for (int i=n;i>=0;i--){
                    printf("%d",A[i]);
                }
                printf("\t");
                printf("Q: ");
                for (int i=n;i>=0;i--){
                    printf("%d",Q[i]);
                }
                printf("\tSet Q[0]=0\n\n");
            }
            else{
                Q[0]=1;
                printf("A: ");
                for (int i=n;i>=0;i--){
                    printf("%d",A[i]);
                }
                printf("\t");
                printf("Q: ");
                for (int i=n;i>=0;i--){
                    printf("%d",Q[i]);
                }
                printf("\tSet Q[0]=1\n\n");
            }
        }
        if(A[n]==1){
            add(A,M,n);
            printf("A: ");
            for (int i=n;i>=0;i--){
                printf("%d",A[i]);
            }
            printf("\t");
            printf("Q: ");
            for (int i=n;i>=0;i--){
                printf("%d",Q[i]);
            }
            printf("\tA <-- A+M\n");
        }
    }
    else{
        printf("Enter a valid Choice");
        // getch();
        return 0;
    }
    printf("A(Remainder): ");
    for (int i=n;i>=0;i--){
        printf("%d",A[i]);
    }
    printf("\n");
    printf("Q(Quotient) : ");
    for (int i=n;i>=0;i--){
        printf("%d",Q[i]);
    }
    int rem=0, quo=0;
    for(int i=n;i>=0;i--){
        rem+=A[i]*pow(2,i);
    }
    for(int i=n;i>=0;i--){
        quo+=Q[i]*pow(2,i);
    }
    printf("\nRemainder in Decimal after sign correction: %d", rem*sign_a);
    printf("\nQuoitent in Decimal after sign correction : %d\n", quo*sign_a*sign_b);
    // getch();
    return 0;
}