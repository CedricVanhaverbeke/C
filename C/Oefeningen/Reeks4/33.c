#include <stdio.h>
#include <string.h>
#define AANTAL_WOORDEN 3
#define GEMIDDELDE_LENGTE_WOORDEN 7
#define LENGTE_ARRAY_T (GEMIDDELDE_LENGTE_WOORDEN+1) * AANTAL_WOORDEN

/*Met schuivende pointers*/
void lees(char ** pt){
    int i;
    char woord[GEMIDDELDE_LENGTE_WOORDEN+1];

    for(i = 0; i<AANTAL_WOORDEN; i++){
        fgets(woord, GEMIDDELDE_LENGTE_WOORDEN + 1, stdin);
        woord[strlen(woord)-1] = 0;
        strcpy(*pt, woord);
        *(pt+1) = *pt + (int)strlen(*pt)+1;
        pt++;
    }
    /*Laatste element van t op 0 zetten*/
    *pt=0;
}

void schrijf(char ** pt){
    while(*pt != 0){
        printf("%s ", *pt);
        pt++;
    }
}

int main(){
    char* pt[AANTAL_WOORDEN+1]; /* zodat je ook nog een nullpointer
                                kan wegsteken op het einde van de
                                pointertabel */
    char t[LENGTE_ARRAY_T];
    pt[0] = t;
    printf("Geef %d woorden in:\n",AANTAL_WOORDEN);
    lees(pt); /* leest alle woorden in */
    schrijf(pt); /* schrijft alle woorden onder elkaar uit*/
    return 0;
}
