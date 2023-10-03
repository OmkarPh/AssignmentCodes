#include<stdio.h>
#include<stdlib.h>
struct node
{
    int ID ;
    int quantity ;
    int priceperunit ;
    int price ;
    struct node*next ;
}*first = NULL ;
void Insert(int ID,int quantity,int priceperunit)
{
    struct node*p = first ;
    struct node* t = NULL ;
    t = (struct node*)malloc(sizeof(struct node)) ;
    t->ID = ID ;
    t->quantity = quantity ;
    t->priceperunit = priceperunit ;
    t->price = (quantity*priceperunit) ;
    t->next = NULL ;
    if(first==NULL)
    {
        first = t ;
    }
    else
    {
        while(p->next!=NULL)
        {
            p = p->next ;
        }
        p->next = t ;
    }  
}
void SearchAndChangeQuantity(int ID,int newquantity)
{
    struct node*p ;
    p = first ;
    while(p->ID != ID)
    {
        p = p->next ;
    }
    p->ID = newquantity ;
}
void productname(int Id)
{
    if(Id==2876)
        printf("Apple") ;
    else if(Id==2877)
        printf("Oil") ;
    else if(Id==2878)
        printf("Milk") ;
    else
        printf("Spinach") ;
}
void checkout()
{
    int total = 0 ;
    int sr = 1 ;
    struct node*p ;
    p = first ;
    printf("______________________________________________________________________________________________________________\n") ;
    printf("Sr.no.\t\t") ;
    printf("Product name\t\t") ;
    printf("price per unit\t\t") ;
    printf("Quantity\t\t") ;
    printf("Price\t\t\n") ;
    printf("______________________________________________________________________________________________________________\n") ;
    while(p!=NULL)
    {
        printf("%d.\t\t",sr) ;
        productname(p->ID) ;
        printf("\t\t\t%d\t\t\t",p->priceperunit) ;
        printf("%d\t\t\t",p->quantity) ;
        printf("Rs %d/-\t\t\n",p->price) ;
        total += p->price ;
        sr++ ;
        p = p->next ;
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t______________________\n") ;
    printf("Grand Total :") ;
    printf("\t\t\t\t\t\t\t\t\t\tRs %d/-\n",total) ;
    printf("______________________________________________________________________________________________________________\n") ;
}
int AlreadySelected(int* Quantity,int Id)
{
    int x = 0 ;
    int choice2 ;
    printf("You have alrready selected this item\n") ;
                printf("1.modify the quantity ?\n") ;
                printf("2.Don't modify\n") ;
                printf("Enter your choice : ") ;
                scanf("%d",&choice2) ;
                printf("-----------------------------\n") ;
                switch(choice2)
                {
                    case 1 :
                        printf("exsisting Quantity : %d\n",*Quantity) ;
                        printf("Enter new Quantity : ") ;
                        scanf("%d",&x) ;
                        *Quantity = x ;
                        SearchAndChangeQuantity(Id,x) ;
                        printf("Quantity of ") ;
                        productname(Id) ;
                        printf(" Modified\n") ;
                        printf("-----------------------------\n") ;
                        break ;
                    case 2 :
                        return 1 ;
                        break ;
                }
}
int main()
{
    int item ;
    int PriceOfApple = 150 ;
    int PriceOfOil = 100 ;
    int PriceOfMilk = 46 ;
    int PriceOfSpinach = 30 ;
    int QuantityOfApple ;
    int QuantityOfOil ;
    int QuantityOfMilk ;
    int QuantityOfSpinach ;
    int choice ;
    int choice2 ;
    int choice3 ;
    int IdOfApple = 2876 ;
    int IdofOil = 2877 ;
    int IdofMilk = 2878 ;
    int IdofSpinach = 2879 ;
    int counterforapple=0 ;
    int counterforoil = 0 ;
    int counterformilk = 0 ;
    int counterforspinach = 0 ;
    int n = 1 ;
    printf("\n\t\t\t\t\t\t\t\t----------- SURYAN STORE -----------\t\t\t\t\t\t\t\t\n") ;
    again :
    printf("\t\t\t\t\t\t\t\t    Items availabe in our store : \n");
    printf("\t\t\t\t\t\t\t\t\t-----1.Apple  -----\n");
    printf("\t\t\t\t\t\t\t\t\t-----2.Oil    -----\n");
    printf("\t\t\t\t\t\t\t\t\t-----3.Milk   -----\n");
    printf("\t\t\t\t\t\t\t\t\t-----4.spinach-----\n");
    printf("\t\t\t\t\t\t\t\t    Select your item : ");
    scanf("%d",&item) ;
    printf("-----------------------------\n") ;
    switch(item)
    {
        case 1:
            if(counterforapple>=1)
            {
                counterforapple++ ;
                if(AlreadySelected(&QuantityOfApple,IdOfApple)) 
                {
                    goto here ;
                }
                else 
                    break ;
            }
            else
            {
                printf("item selected : Apple\n") ;
                printf("Price : %drs per kg\n",PriceOfApple) ;
                printf("Enter quantity(in kgs) : ") ;
                scanf("%d",&QuantityOfApple) ;
                if(QuantityOfApple==0)
                {
                    printf("Very less Quantity\n") ;
                    printf("-----------------------------\n") ;
                    goto again ;
                }
                else
                {
                    Insert(IdOfApple,QuantityOfApple,PriceOfApple) ;
                    printf("item added to your cart\n") ;
                    counterforapple++ ;
                    printf("-----------------------------\n") ;
                    goto here ;
                }
                printf("-----------------------------\n");
                break ;
            }
        case 2 :
            if(counterforoil>=1)
            {
                counterforoil++ ;
                if(AlreadySelected(&QuantityOfOil,IdofOil)) 
                {
                    goto here ;
                }
                else 
                    break ;
            }
            else
            {
                printf("item selected : Oil\n") ;
                printf("Price : %drs per kg\n",PriceOfOil) ;
                printf("Enter quantity(in pouch) : ") ;
                scanf("%d",&QuantityOfOil) ;
                if(QuantityOfOil==0)
                {
                    printf("Very less Quantity\n") ;
                    printf("-----------------------------\n") ;
                    goto again ;
                }
                else
                {
                    Insert(IdofOil,QuantityOfOil,PriceOfOil) ;
                    printf("item added to your cart\n") ;
                    counterforoil++ ;
                    printf("-----------------------------\n") ;
                    goto here ;
                    break ;
                }
            }
        case 3 :
            if(counterformilk>=1)
            {
                counterforspinach++ ;
                if(AlreadySelected(&QuantityOfMilk,IdofMilk)) 
                {
                    goto here ;
                }
                else 
                    break ;
            }
            else
            {
                printf("item selected : Milk\n") ;
                printf("Price : %drs per litre\n",PriceOfMilk) ;
                printf("Enter quantity(in litres) : ") ;
                scanf("%d",&QuantityOfMilk) ;
                if(QuantityOfMilk==0)
                {
                    printf("Very less Quantity\n") ;
                    printf("-----------------------------\n") ;
                    goto again ;
                }
                else
                {
                    Insert(IdofMilk,QuantityOfMilk,PriceOfMilk) ;
                    printf("item added to your cart\n") ;
                    counterformilk++ ;
                    printf("-----------------------------\n") ;
                    goto here ;
                    break ;
                }
            }
        case 4 :
            if(counterforspinach>=1)
            {
                counterforspinach++ ;
                if(AlreadySelected(&QuantityOfSpinach,IdofSpinach)) 
                {
                    goto here ;
                }
                else 
                    break ;
            }
            else
            {
                printf("item selected : Spinach\n") ;
                printf("Price : %drs per bundle\n",PriceOfSpinach) ;
                printf("Enter quantity(in bundle) : ") ;
                scanf("%d",&QuantityOfSpinach) ;
                if(QuantityOfSpinach==0)
                {
                    printf("Very less Quantity\n") ;
                    printf("-----------------------------\n") ;
                    goto again ;
                }
                else
                {
                    Insert(IdofSpinach,QuantityOfSpinach,PriceOfSpinach) ;
                    printf("item added to your cart\n") ;
                    counterforspinach++ ;
                    printf("-----------------------------\n") ;
                    goto here ;
                    break ;
                }
            }
        default :
            printf("Please enter valid input\n");
            goto again ;
            break ;
    }
    here :
    while(n!=0)
    {
        printf("1.Add more items\n") ;
        printf("2.Proceed to checkout\n") ;
        printf("Enter your choice : ") ;
        scanf("%d",&choice) ;
        printf("-----------------------------\n");
        switch(choice)
        {
            case 1 :
                    goto again ;
                    break ;
            case 2 :
                    checkout() ;
                    printf("1.Proceed to checkout.............\n") ;
                    printf("2.Cancel order....................\n") ;
                    printf("Enter your choice : ") ;
                    scanf("%d",&choice3) ;
                    if(choice3==1)
                        {
                            printf("\n\t\t\t\t\t\t\t\t----------- Order Confirmed.......!-----------\n") ;
                            n = 0 ;
                        }
                    else if (choice3==2) 
                    {
                        printf("\n\t\t\t\t\t\t\t\t----------- Order canceled........!-----------\n") ;
                        n = 0 ;
                    }
                    else 
                        printf("Enter valid Input.....!\n") ;
                    break ;
            default :
                    printf("Please enter valid input\n");
                    break ;
        }
    }
}