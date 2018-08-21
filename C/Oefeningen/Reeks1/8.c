#include <stdio.h>

int cijfersom(int x){
    int som = 0;
    while(x > 0){
        som += x%10;
        x /= 10;
    }
    return som;
}

int cijfersom_herhaald ( int x ) {
    int som = cijfersom(x);
    while(som > 9){
        x /= 10;
        som = cijfersom(x);
    }
    return som;
}

int cijfersom_recursief( int x ){
    int som;
    if(cijfersom(x) < 9){
        return cijfersom(x);
    } else {
        som = cijfersom_recursief(x/10);
    }
    return som;
}

int main(void){
    int i, getal;
    for(i = 0; i < 3; i++){
        scanf("%d", &getal);
        if(getal > 0){
            printf("Cijfersom van %d is: %d\n", getal, cijfersom(getal));
        } else {
            printf("Geef een positief getal in aub\n");
            i--;
        }
    }
}

