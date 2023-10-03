#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct term{
    double coef;
    double pow;
    struct term *next;
};
double evaluatePoly(struct term *root, double x){
    double ans=0;
    while(root!=NULL){
        ans += root->coef * pow(x,root->pow);
        root = root->next;
    }
    return ans;
}
struct term* addTwoPoly(){

}
struct term* createPoly(){
    int n;
    struct term *poly, *temp;
    struct term *traveller;
    poly = temp = NULL;
    printf("Enter the no of nodes you want in the polynomial: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        printf("For term %d, Coef: ",i);
        temp = (struct term*)malloc(sizeof(struct term));
        scanf("%lf",&temp->coef);
        printf("Power: ");
        scanf("%lf",&temp->pow);
        if(poly==NULL){
            poly = temp;
            traveller = poly;
        }
        else
        {
            traveller->next = temp;
            traveller = temp;
        }
    }
        return poly;
}
int main(){
    double n;
    struct term* poly1 = createPoly();
    printf("Enter value for x for poly1:");
    scanf("%lf",n);
    printf("%lf",evaluatePoly(poly1,n));
    return 0;
}