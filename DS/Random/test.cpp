#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double areaSquared(triangle tr){
    double p = (double)(tr.a+tr.b+tr.c)/2;
    return (double)p*(p-tr.a)*(p-tr.b)*(p-tr.c);
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    double *areaAll = (double*)malloc(sizeof(double));
    for(int i=0; i<n; i++)
        areaAll[i] = areaSquared(tr[i]);
        
    // BubbleSort
    int flag = 0;
    for(int i=0; i<n-1; i++){
        flag = 0;
        for(int j=0; j<n-1; j++){
            if(areaAll[j]>areaAll[j+1]){
               double tem = areaAll[j];
                areaAll[j] = areaAll[j+1];
                areaAll[j+1] = tem;
//swapping array of areas in ascending
//and simuntaneously the structure contents
                int temp;
                temp=tr[j].a;
                tr[j].a=tr[j+1].a;
                tr[j+1].a=temp;
                temp=tr[j].b;
                tr[j].b=tr[j+1].b;
                tr[j+1].b=temp;
                temp=tr[j].c;
                tr[j].c=tr[j+1].c;
                tr[j+1].c=temp;
                flag = 1;
            }
        }
        if(flag==0)
                break;
    }
}
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = (triangle*)malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}