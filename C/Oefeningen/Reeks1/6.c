#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float bereken(float x, int n){
    int i;
    int teller = -1;
    float noemer, noemerbereken, waarde, resultaat;
    noemer = noemerbereken = 2*n + 1;

    for(i = 1 ; i < n ; i++){
       teller *= teller; 
    }

    while(noemerbereken > 1){
        noemerbereken--;
        noemer *= noemerbereken;
    }    
    
    waarde = x;
    for(i = 2*n + 1; i > 1; i--){
        waarde *= x;
    }

    resultaat = (teller / noemer ) * waarde;
    if(n == 0){
        resultaat = x;
    }
    return resultaat;
}

float sinus(float x){
    int n = 0;
    int i = 0;
    float vorige, resultaat = 0;

    while(fabsf(vorige + bereken(x,n)) - fabsf(vorige) > 0.000000001){
        vorige = resultaat;
        resultaat = vorige + bereken(x,n);
        n++;
        i++;
    }
   return resultaat;
}

int main(void){
    float rad;
    scanf("%f", &rad);

    printf("%f\n", rad);
    printf("%f\n", sinus(rad));
}


