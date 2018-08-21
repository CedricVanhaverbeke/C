#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int index_van(float * array, int lengte, float getal){
    int index;
    for(index = 0; index < lengte; index++){
        if(fabsf(array[index] - getal) < 0.00001){
            return index;
        }
    }

    return -1;
}

int main(void){
    float getallen[] = { 1.3 , 6.9 , 7.5 };
    printf("Geef mij de index van %0.1f: %d", 6.9, index_van(getallen, 3, 6.9));
    return 0;
}
