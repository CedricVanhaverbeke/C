#include <stdio.h>

void pivoteer(char * begin, char * na_einde, char * pivot){
    /*Om ergens op te initialiseren*/
    char * loper1 = begin;
    char * loper2 = na_einde;
    char hulp;

    loper1 = pivot;
    loper2 = pivot;
    while(loper1 != begin && loper2 != na_einde){
        loper1--;
        loper2++;
        hulp = *loper1;
        *loper1 = *loper2;
        *loper2 = hulp;

    }
    loper1=0;
    loper2=0;
}

void schrijf(char * begin, char * eind){
    while(begin != eind){
        printf("%c", *begin);
        begin++;
    }
    printf("\n");
}

int main(void){
    char tekst[] = {'b','d','?','z','g','o','e','z','e','b',
    ' ','d','i','g','!','h','o','s','v'};
    pivoteer(tekst+7,tekst+12,tekst+9);
    schrijf(tekst+4,tekst+15);
}
