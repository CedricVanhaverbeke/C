#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct knoop knoop;
struct knoop {
    int d;
    knoop * opv;
};

void voeg_vooraan_toe(int getal, knoop ** l){
    knoop * hulp = *l;
    *l = (knoop *) malloc(sizeof(knoop));
    (*l)->d = getal;
    (*l)->opv = hulp;
}

/* EZ manier om zo'n lijst op te bouwen 
    Getal gaat altijd naar omlaag
    Aangezien getal altijd lager gaat gaan en rand ook 0 kan genereren kunnen er ook dubbels zijn
*/

knoop * maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens){
    knoop * l = 0;
    int getal = bovengrens ;
    int i ;
    srand(time(NULL));
    for ( i =0; i < aantal ; i ++) {
        getal -= rand () %3;
        voeg_vooraan_toe ( getal ,& l ) ;
    }
    return l ;
}

/* Hier geen dubbele pointer nodig omdat we de tweede dubbel altijd gaan verwijderen */
void verwijder_dubbels(knoop * l){
    while(l->opv != 0){
        while(l->opv->d == l->d){
            knoop * hulp = l->opv->opv;
            free(l->opv);
            l->opv = hulp;
        }
        l = l->opv;
    }
}

void print_lijst(knoop * l){
    while(l != 0){
        printf("%d ", l->d);
        l = l->opv;
    }
}

void geef_lijst_vrij(knoop ** l){
    if(*l != 0){
        geef_lijst_vrij( &((*l)->opv) );
        free(*l);
        *l = 0;
    }
}

/* Gaat de pijl teruggeven  */
/* We willen het juiste adres teruggeven, belangrijk dus dat dit een dubbele pointer is */
knoop ** zoek(int x, knoop ** lijst){
    knoop ** zoek = lijst;
    while( *zoek != 0 && x < (*zoek)->d ){
        *zoek = (*zoek)->opv;
    }
    return zoek;
}

void voeg_getal_toe(int getal, knoop ** lijst){
    knoop ** plaats = zoek(getal, lijst);
    knoop * nieuw = malloc(sizeof(knoop));
    knoop ** hulp = &((*plaats)->opv);
    nieuw->opv = *hulp;
    (*plaats)->opv = nieuw;
}

int main(){
    knoop * l = maak_gesorteerde_lijst_automatisch(10,100);
    print_lijst(l);
    
    printf("\nnu worden dubbels verwijderd: \n");
    verwijder_dubbels(l); 
    printf("\nna verwijderen van dubbels: \n\n");
    print_lijst(l);
    ("\nToevoegen van een nieuw getal:");
    voeg_getal_toe(3, &l);
    print_lijst(l);

    geef_lijst_vrij(&l);
    
    return 0;
}
