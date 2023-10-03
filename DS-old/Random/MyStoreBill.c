#include<stdio.h>
#include<stdlib.h>
int productQty[5];
int totalCost=0;
int sr=1, amount =0;
int productRate[5] = {40, 45, 35, 20, 5};
char productName[5][10] = {"Banana ","Milk  ","Rice  ","Spinach","Wafers "};
char productUnit[5][10] = {"dozen","litre","kilogram","bundle","packet"};
int i, j;
void begin(){
    totalCost = 0;
    sr=1;
    amount =0;
    for(i=0; i<5; i++)
        productQty[i] = 0;
}
int askForItems(){
    int choice;
    printf("Items availabe in our store : \n");
    printf("--  1. Banana  --\n");
    printf("--  2. Milk  --\n");
    printf("--  3. Rice  --\n");
    printf("--  4. Spinach  --\n");
    printf("--  5. Wafers  --\n");
    printf("Select your item : ");
    scanf("%d",&choice);
    printf("--------------------\n");

    return choice-1;
}
int askForQty(int index){
    int choice = -1;
    if(productQty[index]==0){
        printf("You selected %s\n", productName[index]);
        printf("Rate for %s: Rs. %d per %s\n", productName[index], productRate[index], productUnit[index]);
        printf("Simply enter -1, if you don't want this item.\n");
        printf("No of %ss you want: ",productUnit[index]);
        scanf("%d",&choice);
    }
    else{
        printf("%s is already in your cart!\n", productName[index]);
        printf("%s in your cart: %d %s\n",productName[index], productQty[index], productUnit[index]);
        printf("Rate for %s: Rs. %d per %s\n", productName[index], productRate[index], productUnit[index]);
        printf("1. Don't modify the existing Qty.\n");
        printf("2. Modify existing quantity.\n");
        scanf("%d",&choice);
        if(choice==2){
            printf("New Qty: ");
            scanf("%d",&choice);
            printf("Successfully updated the Qty to -> %d %s\n",choice,productUnit[index]);
        }else
            choice = -1;
    }
    
    return choice;
}
void displayBill(){
    printf(".------------------------------------------------------------------------");
    printf("----------------------------------------------------------------.\n");
    printf("|\tSr.no.\t\t") ;
    printf("|\tProduct name\t\t") ;
    printf("|\tRate \t\t") ;
    printf("|\t Quantity\t\t ") ;
    printf("|\t Amount\t\t |\n") ;
    printf("|------------------------------------------------------------------------");
    printf("----------------------------------------------------------------|\n");
    totalCost = 0;
    i=0;
    while(i<5){
        if(productQty[i] > 0){
            amount = productRate[i]*productQty[i];
            printf("| \t  %d\t\t| \t  %s \t\t| \t %d\t\t| \t    %d\t\t\t |\t  %d\t\t |\n",sr, productName[i],productRate[i], productQty[i], amount);
            totalCost += amount;
            sr++;
        }
        i++;
    }
    printf("|------------------------------------------------------------------------");
    printf("----------------------------------------------------------------|\n");
    printf("|     Grand Total\t\t\t\t\t\t\t\t\t\t\t\t |\t %d\t\t |\n",totalCost);
    printf("'------------------------------------------------------------------------");
    printf("----------------------------------------------------------------'\n");
}
int main(){
    int choiceIndex, n, more;
    while(1){
        begin();
        printf("\tWelcome to SURYAN STORE !\n");
        while(1){
            choiceIndex = askForItems();
            n = askForQty(choiceIndex);
            if(n!=-1){
                productQty[choiceIndex] = n;
            }
            printf("Do you want to add more items or Proceed to checkout ?\n");
            printf("1. Add more items\n");
            printf("2. Proceed to checkout\n");
            scanf("%d",&more);
            if(more==2)
                break;
        }
        break;
    }

    for(i=0; i<5; i++){
        totalCost += productQty[i] * productRate[i];
        printf("%s: %d %ss\n",productName[i],productQty[i],productUnit[i]);
    }
    printf("Total: %d\n",totalCost);

    displayBill();
    printf("\n------------------------------------------------------------------ Thank you ! -----------------------------------------------------------\n");
    return 0;
}