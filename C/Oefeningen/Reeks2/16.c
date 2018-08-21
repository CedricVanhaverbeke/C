#include <stdio.h>
#include <stdlib.h>
#define AANTAL 26

void verwerktekst(int * array){
    int c;
    while((c = getchar()) != '$'){
        array[c - 'a']++;
    }
}

void print_horizontaal(int * array){
    int i,j;
    for(i=0; i < AANTAL; i++){
        printf("%c:\t", 'a' + i);
        for(j=0;j<array[i]; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(void){
    int array[AANTAL] = {0};
    verwerktekst(array);
    print_horizontaal(array);
    
}
