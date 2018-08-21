#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int waarde;
    int aantal_delers;
    int * delers;
} Deeltal;

void schrijf_ints(int * array, int lengte){
    int i;
    printf("%d", array[0]);
    for(i = 1; i<lengte; i++){
            printf("-");
            printf("%d", array[i]);
    }
}

void schrijf_deeltal(Deeltal * d){
    printf("%d\t", d->waarde);
    schrijf_ints(d->delers, d->aantal_delers);
}

int main(void){
    Deeltal d;
    d.waarde = 6;
    d.aantal_delers = 3;
    d.delers = (int*) malloc(sizeof(int) * d.aantal_delers);
    d.delers[0] = 1;
    d.delers[1] = 2;
    d.delers[2] = 3;
    schrijf_deeltal(&d);
}
