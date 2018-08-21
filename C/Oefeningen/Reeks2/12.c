#include <stdio.h>

void schrijf_even_posities(char * array, int lengte){
    int i;
    for(i = 0; i < lengte; i+=2 ){
        printf("%c", array[i]);
    }
    printf("\n");
}

int main(void){
    char letters[] = {'p','o','r','e','o','i','f','o','i','e','c','i','i',':',
'a','-','t','(' };

    printf("De lengte van de array is: %lu\n", sizeof(letters)/sizeof(char));
    schrijf_even_posities(letters, sizeof(letters)/sizeof(char));

    return 0;
}


