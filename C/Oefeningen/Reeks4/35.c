#include <stdio.h>
#include <stdlib.h>
#define AANTAL 3

typedef struct {
    int waarde;
    int aantal_delers;
    int * delers;
} Deeltal;

int aantal_delers_van(int x){
    int i = 2;
    int aantal = 1;
    while(i<=x/2){
        if(x%i == 0){
            aantal++;
        }
        i++;
    }
    return aantal;
}

int * delers_van(int x){
    int * delers = malloc(sizeof(int)*aantal_delers_van(x));
    int i;
    int index = 0;
    for(i = 2; i <= x/2; i++){
        if(x%i == 0){
            delers[index++] = i;
        }
    }
    delers[index] = x;
    return delers;
}

void vul_aan(Deeltal * d){
    d->aantal_delers = aantal_delers_van(d->waarde);
    d->delers = delers_van(d->waarde);
}

void schrijf_deeltal(const Deeltal *d){
    int i;
    printf("deeltal %d met %d delers: ", d->waarde, d->aantal_delers);
    for(i=0; i<d->aantal_delers; i++){
        printf("%d ", d->delers[i]);
    }
    printf("\n");
}

void schrijf_deeltallen(const Deeltal * d, int aantal){
    int i;
    for(i=0; i<aantal; i++){
        schrijf_deeltal(&d[i]);
    }
}

void lees_deeltal(Deeltal * d){
    scanf("%d", &(d->waarde));
    vul_aan(d);
}

void lees_deeltallen(Deeltal * d, int aantal){
    int i;
    for(i = 0; i < aantal; i++){
        lees_deeltal(&d[i]);
    }
}

int main(void){
    Deeltal * d = malloc(sizeof(Deeltal) * AANTAL);
    lees_deeltallen(d, AANTAL);
    schrijf_deeltallen(d, AANTAL);
    
}

/*Vrijgeven van deeltallen zit hier nog niet bij, so you know*/
