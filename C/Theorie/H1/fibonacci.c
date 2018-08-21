#include <stdio.h>

void fibonacci(int);
int fibonacci_recursief(int);

int main(void){
    int fibo = fibonacci_recursief(6);
    printf("%d", fibo);
    return 0;
}

void fibonacci(int x){
    int i = 1;
    int vorige = 0;
    int nu = 1;
    int fibo;
    for(i; i < x; i++){
        fibo = vorige + nu;
        vorige = nu;
        nu = fibo;
    }
    printf("%d", nu);
}

int fibonacci_recursief(int x){
    int fibo = 1;
    int vorige = 1;

    if(x == 1 || x == 2){
        return 1;
    } else {
       return fibonacci_recursief(x-2) + fibonacci_recursief(x-1);
    }
    return fibo;
}



