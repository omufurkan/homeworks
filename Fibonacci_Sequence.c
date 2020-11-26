#include <stdio.h>

int fonkcagirilma = 0;
int fibonacci(int hesaplananeleman){
    fonkcagirilma += 1;
    if(hesaplananeleman == 1){
        return 1;
    }
    else if(hesaplananeleman == 0){
        return 0;
    }
    else{
        return fibonacci(hesaplananeleman - 2) + fibonacci(hesaplananeleman - 1);
    }
}
int main(){
    int fbhesap;
    printf("Fibonacci serisinin kacinci elemanini hesaplamak istiyorsunuz ?: ");
    scanf("%d",&fbhesap);
    printf("Fibonacci serisinin %d.elemani: %d\n",fbhesap,fibonacci(fbhesap));
    printf("Serinin %d. elemaninin hesaplanmasi icin fonksiyon cagirilma sayisi: %d",fbhesap,fonkcagirilma);
}