// Er verschijnen negatieve getallen in de lijst , te wijten aan overflow .

#include <stdio.h>

int faculteit(int x){
    int fac = 1;
    if(x == 0){
        return 1;
    }
    while(x > 0){
        fac *= x;
        x--;
    }

    return fac;
}

void schrijf_faculteit(int x){
    printf("Faculteit van %d: %d", x, faculteit(x));
}

int main(void){
    schrijf_faculteit(20);
}
