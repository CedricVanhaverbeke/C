#include <stdio.h>
#define SIZE 8

void schuif_naar_links(char * array, int lengte){
    char eerste = *array;
    int i;
    for(i = 0; i < lengte; i++){
        array[i] = array[i+1];
    }

    array[lengte-1] = eerste;
}


int main(void){
    int i;
    char array[] = {'s','a','p','a','p','p','e','l'};
    schuif_naar_links(array, SIZE);
    schuif_naar_links(array, SIZE);
    schuif_naar_links(array, SIZE);

    for(i = 0; i < 8; i++){
        printf("%c", array[i]);
    }
    return 0;
}
