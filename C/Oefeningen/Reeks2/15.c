#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define AANTAL 20
#define ONDERGRENS 100
#define BOVENGRENS 120

int main(void){
    int i, random;
    srand(time(NULL));
    int array[BOVENGRENS-ONDERGRENS+1] = { 0 };
    for(i = 0; i<AANTAL+1; i++){
        random = rand()%20 + ONDERGRENS + 1;
        printf("%d\n", random);
        array[random%100]++;
    }

    for(i=0; i<AANTAL; i++){
        if(array[i] == 0){
            printf("%d ", ONDERGRENS+i);
        }
    }

    return 0;
}