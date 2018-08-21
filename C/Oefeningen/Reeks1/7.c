#include <stdio.h>
#define AANTAL 3

int main(void){
    
    int i = 0;
    int getal,som,aantal;
    som = aantal = 0;

    while(i < AANTAL && getal >= 0){
        scanf("%d", &getal);
        som += getal;
        aantal++;
        i++;
    }
    
    if(getal < 0){
        aantal--;
        som -= getal;
    }
 
    printf("De gebruiker gaf %d positieve getallen op.\n", aantal);
    printf("De som van de getallen is %d\n", som);

    return 0;
}
