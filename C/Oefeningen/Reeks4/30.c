#include <stdio.h>
#include <string.h>
#define AANTAL 6
#define LENGTE 81


typedef struct{
    char naam[LENGTE];
    int leeftijd;
}persoon;

void schrijf_cstring(void * s){
    printf("%s\n", (char*)s);
}

void schrijf_int(void * a){
    printf("%d\n", *((int*)a));
}

void schrijf_persoon(void * p){
    printf("%s (%d)\n", ((persoon*)p)->naam, ((persoon*)p)->leeftijd);
}

void schrijf_array(void * array, int aantal, int grootte, char tussenteken, void (*schrijf)(void*)){
    int i = 0;
    (*schrijf)(array);
    for(i=1; i<aantal; i++){
        printf("%c", tussenteken);
        schrijf((char*)array + grootte*i);
    }
}


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

    schrijf_cstring(namen[0]);
    schrijf_int(leeftijden);
    schrijf_persoon(personen);

    schrijf_array(personen, AANTAL, sizeof(persoon), '-', *schrijf_persoon);

    return 0;
}
