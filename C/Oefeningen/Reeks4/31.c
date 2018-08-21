#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

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

int main(void){
    char * tekst = lees();
    printf("Woord: %s", tekst);
    free(tekst);
    return 0;
}
