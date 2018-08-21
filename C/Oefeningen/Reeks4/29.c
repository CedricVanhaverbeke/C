#include <stdio.h>
#include <string.h>
#define AANTAL 6
#define LENGTE 81


typedef struct{
    char naam[LENGTE];
    int leeftijd;
}persoon;


int main(){
    int i;
    char * namen[AANTAL] = {"Evi","Jaro","Timen","Youri","Ashaf","Jennifer"};
    int leeftijden[AANTAL] = {21,30,18,14,22,19};
    
    persoon personen[AANTAL];
    for(i = 0; i<AANTAL; i++){
        strcpy(personen[i].naam, namen[i]);
        personen[i].leeftijd = leeftijden[i];
    }

    for(i = 0; i<AANTAL; i++){
        printf("%s is %d jaar oud\n", personen[i].naam, personen[i].leeftijd);
    }

    return 0;
}
