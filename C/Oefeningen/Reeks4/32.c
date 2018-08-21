#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4
#define MAXAANTAL 6

char * lees(){
    char s[MAX+1];
    int lengte = strlen(s);
    char * new;
    fgets(s, MAX+1,stdin);
    /*Als de ingelezen tekst te klein is*/
    if(s[lengte - 1] == '\n'){
        s[lengte - 1] = 0;
        lengte--;
    }

    /*Als de ingelezen tekst te groot is*/
    s[lengte-1] = 0;
    while(getchar() != '\n'); /*Buffer uitlezen*/

    new = malloc(sizeof(char) * lengte + 1);
    strcpy(new,s);
    return new;
}

char ** lees_meerdere(){
    int i = 0, j = 0;
    char * woorden[MAXAANTAL];
    char *woord = lees();
    while(i < MAXAANTAL-1 && (strcmp(woord, "STOP") != 0)){
        woord = lees();
        i++;
    }
    if(i != 5){
        woorden[i] = 0;
    }
    free(woord);

    char ** nieuwe_teksten = malloc(sizeof(char*)*i + 1);
    while(j < i){
        nieuwe_teksten[j] = woorden[j];
        j++;
    }
    nieuwe_teksten[j] = 0;
    return nieuwe_teksten;
}

void geef_vrij(char ** teksten){
    while(*teksten != NULL){
        free(*teksten);
        teksten++;
    }
}



int main(void){
    char ** teksten = lees_meerdere();
    geef_vrij(teksten); /* Inhoud van de teksten */
    free(teksten); /* Teksten zelf */
    return 0;
}
