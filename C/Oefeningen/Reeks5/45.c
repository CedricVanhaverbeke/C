#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct knoop knoop;
struct knoop {
    char * s;
    knoop * opv;
};


knoop ** geef_array_van_lijsten(int aantal){
    char s[80];
    int teller = 0, i;
    knoop ** knoop_array = (knoop**) malloc(sizeof(knoop*)*aantal);
    knoop ** hulppointers = (knoop**) malloc(sizeof(knoop*)*aantal);

    for(i=0; i<aantal; i++){
        knoop_array[i] = 0;
        hulppointers[i] = 0;
    }

    scanf("%80s", s);
    while(strcmp(s, "STOP") != 0){
        char * woord = malloc(sizeof(char)*strlen(s) + 1);
        knoop * nieuw = malloc(sizeof(knoop));
        strcpy(woord,s);
        scanf("%s", s);
        nieuw->s = woord;

        if(knoop_array[teller%aantal] == 0 && hulppointers[teller%aantal] == 0){
            knoop_array[teller%aantal] = nieuw;
            hulppointers[teller%aantal] = nieuw;
        } else {
            hulppointers[teller%aantal]->opv = nieuw;
            hulppointers[teller%aantal] = nieuw;
        }
        teller++;
    }

    for(i=0; i<aantal; i++){
        hulppointers[i]->opv = 0;
    }
    
    return knoop_array;
}

void schrijf_array(knoop ** l, int aantal){
    int i;
    for(i=0; i<aantal; i++){
        while(l[i] != 0){
            printf("%s ", l[i]->s);
            l[i] = l[i]->opv;
        }
        printf("\n");
    }
}

int main(void){
    knoop ** l = geef_array_van_lijsten(3);
    schrijf_array(l, 3);
}
