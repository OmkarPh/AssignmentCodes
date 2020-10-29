#include<iostream>
using namespace std;
void primeSeive(int *arr, int maxValue){
    // All odds are prime
    for(int i=3; i<=maxValue; i+=2){
        arr[i]=1;
    }

    

}
int main(){
    int primeSeivedArr[1000] = {0};
    primeSeive(primeSeivedArr, 1000);

    return 0;
}