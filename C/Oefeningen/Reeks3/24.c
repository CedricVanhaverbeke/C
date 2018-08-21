#include <stdio.h>

void verzetNaarEersteHoofdletter(const char ** p){
   while(**p != 0 && (**p < 'A' || **p > 'Z')){
       (*p)++;
   }
}

const char * verzetNaarEersteKleineLetter(const char * p){
    while(*p != 0 && (*p < 'a' || *p > 'z')){
       p++;
   }
   return p;
}

void schrijf(const char * begin, const char * eind){
    while(begin != eind){
        printf("%c", *begin);
        begin++;
    }
}

int main(void){
    const char zus1[50] = "sneeuwWITje";
    const char zus2[50] = "rozeROOD";
    const char* begin;
    const char* eind;
    begin = zus1;
    verzetNaarEersteHoofdletter(&begin);
    eind = verzetNaarEersteKleineLetter(begin);
    schrijf(begin,eind);

    printf("\n");
    begin = zus2;
    verzetNaarEersteHoofdletter(&begin);
    eind = verzetNaarEersteKleineLetter(begin);
    schrijf(begin,eind); /* schrijft 'ROOD' uit */


    return 0;
}
