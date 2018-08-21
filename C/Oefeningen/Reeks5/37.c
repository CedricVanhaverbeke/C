#include <stdlib.h>
#include <stdio.h>

typedef struct Knoop Knoop;

struct Knoop{
    int d;
    Knoop * opv;
};

void voeg_vooraan_toe(int waarde, Knoop ** l){
    Knoop * hulp = *l;
    *l = (Knoop *) malloc(sizeof(Knoop));
    (*l)->d = waarde;
    (*l)->opv = hulp;
}


void print_lijst(Knoop * l){
    while(l != 0){
        printf("%d ", l->d);
        l = l->opv;
    }
}

void print_lijst_recursief(Knoop *l){
    if(l == 0){

    } else {
        printf("%d ", l->d);
        print_lijst_recursief(l->opv);
    }
}

/* Belangrijk: Geef een dubbele pointer mee, anders maak je een kopie van de lijst!*/
void free_lijst(Knoop ** l){
    Knoop * hulp;
    while(!*l){
        hulp = (*l)->opv;
        free(*l);
    }
}

int main(){
    Knoop * l = 0;
    voeg_vooraan_toe(7, &l);
    voeg_vooraan_toe(3, &l);
    print_lijst_recursief(l);
    free_lijst(&l);
    free(l);
    return 0;
}
