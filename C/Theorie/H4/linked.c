#include <stdio.h>
#include <stdlib.h>

typedef struct Knoop Knoop;

struct Knoop {
    int waarde;
    struct Knoop * next;
};

void print_lijst(Knoop * k){
    while(k != 0){
        printf("%d ", k->waarde);
        k = k->next;
    }
    printf("\n");
}

/* Hier niet mallocen omdat de lijst al bestaat in het geheugen :) */
/* Je mag hier k verzetten omdat een kopie wordt genomen van de knoop */
Knoop * pointer_naar_knoop(Knoop * k, int waarde){
    while(k->waarde != waarde && k!=0){
        k = k->next;
    }
    return k;
}

/* Dubbele pointer hier want je wil de eerste knoop aanpassen, anders geeft hij een kopie mee */
void verplaats_naar_knoop(Knoop ** k, int waarde){
    while((*k)->waarde != waarde && k!= 0){
        *k = (*k)->next;
    }
}

/* Some remarks:
- De knoop naar het eerste element in de lijst moet behouden blijven dus we gebruiken een hulpptr
- Als er slechts 1 element wordt ingevuld
 -- 0: Eerste element moet een nullpointer worden
 -- != 0: Eerste element moet gemalloc't worden naar een knoop

 - Als meerdere elementen worden ingevuld (zolang gescande waarde niet nul)
 -- Vertrek van het begin
 -- Laat de hulppointer verdergaan tot zijn next nul is
    (Belangrijk: niet gewoon de lijst doorlopen! Anders wordt hulp = null. Een nulpointer zweeft gewoon ergens in de ruimte en hangt nergens aan vast)
 -- Dan waarde invullen. Deze mag niet 0 zijn anders heb je 0 als waarde en dat moet dan een nullpointer worden :)
*/
Knoop * maak_lijst(){
    int waarde;
    Knoop * begin = 0;
    Knoop * hulp;

    scanf("%d", &waarde);
    if(waarde != 0){
        begin = malloc(sizeof(Knoop));
        begin->waarde = waarde;
        begin->next = 0;

        while(waarde != 0){
        scanf("%d", &waarde);
        hulp = begin;
            while(hulp->next != 0){
                hulp = hulp->next;
            }
        if(waarde != 0){
            hulp->next = (Knoop *) malloc(sizeof(Knoop));
            hulp->next->waarde = waarde;
            hulp->next->next = 0;
        }
        }
    } 
    return begin;
}

Knoop * maak_omgekeerde_lijst(){
    Knoop ** begin = (Knoop**) malloc(sizeof(Knoop));
    int waarde;
    scanf("%d", &waarde);
    if(waarde == 0){
        *begin = 0;
    } else {
        *begin = (Knoop *)malloc(sizeof(Knoop));
        (*begin)->waarde = waarde;
        (*begin)->next = 0;
    

        scanf("%d", &waarde);
        while(waarde != 0){
            Knoop * new = (Knoop*) malloc(sizeof(Knoop));
            new->waarde = waarde;
            new ->next = *begin;
            *begin = new;
            scanf("%d", &waarde);
        }
    }
    return *begin;
}

void voeg_gesorteerd_toe(Knoop ** l, int waarde){
    Knoop * new = malloc(sizeof(Knoop));
    new->waarde = waarde;

    /* Als het om de eerste knoop gaat */
    if( (*l)->waarde > waarde ){
        Knoop * hulp = *l;
        new->next = hulp;
        *l = new;
    } else {
        Knoop * loper = *l;
        Knoop * hulp = 0;
        while(loper->next != 0 && loper->next->waarde < waarde){
            loper = loper->next;
        }
        hulp = loper->next;
        new->next = hulp;
        loper->next = new;
    }
}

/* Opmerking: Check de volgorde van je while lus! De while lus faalt als een nulpointer opgeroepen wordt! */
void verwijder_knoop(Knoop **l, int waarde){
    Knoop * begin = *l;
    /* Als het om de eerste knoop gaat */
    if( (*l)->waarde == waarde ){
        *l = (*l)->next;
    } else {
       while( (*l)->next != 0 && (*l)->next->waarde != waarde ){
           *l = (*l)->next;
       }

       /* Hier is ofwel de volgende waarde de waarde die weg moet of zitten we bij de laatste knoop */
       if( (*l)->next == 0){
           printf("Waarde niet gevonden in de lijst, niets verwijderd\n");
           *l = begin;
       } else {
           (*l)->next = (*l)->next->next;
       }
    }
}

void vernietig_lijst(Knoop ** l){
    Knoop * h;
    while(*l){
        h = *l;
        *l = (*l)->next;
        free(h);
    }
}

int main(void){
    /* Lijst maken */
    Knoop * l = maak_lijst();
    print_lijst(l);
    verwijder_knoop(&l, 4);
    print_lijst(l);
    return 0;
}
