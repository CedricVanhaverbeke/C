#include <stdio.h>

/* Want default in C = signed. En da's ambetant met bitshiften */
typedef unsigned int uint;

int bit_i(uint x, int i){
    x>>=i;
    return x & 1;
}

uint eenbit(int i){
    uint x = 1;
    return x<<=i;
}

int aantal_eenbits(uint x){
    int aantal = 0;
    while(x != 0){
        aantal += x&1;
        x>>=1;
    }
    return aantal;
}

uint bit_i_aangezet(uint x, int i){
    uint y = 1;
    return x | y<<i;
}

uint bit_i_uitgezet(uint x, int i){
    uint y = 1;
    y<<=i;
    return x & y;
}

uint bit_i_gewisseld(uint x, int i){
    return x ^ eenbit(i);
}

int zijn_gelijk(uint x, uint y){
    return ~(x ^ y) & 0x1;
}

int is_even(uint x){
    return 1 & ~(x & 0x1);
}

void wissel_even_met_oneven_bits(uint * x){
    uint even, oneven;
    even = *x & 0xAA; /* Even bits zijn 1010 1010 */
    /* Ahex = 1010 in binair. Vandaar dus */
    /* We schuiven nu alle bits eentje naar rechts */
    even>>=1;
    oneven =  *x & 0x55; /* Oneven bits zijn 0101 0101 */ 
    /* 5hex = 0101  */
    oneven <<=1; /* Alles eentje naar links */
    *x = oneven ^ even;
}

int main(void){
    uint x = 23;
    wissel_even_met_oneven_bits(&x);
    printf("%d", x);

    return 0;
}
