#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void wis ( char * s ) {
    char * loper = s;
        while (* s != 0) {
            if (islower (*s) || isspace (*s) ) {
            *loper = *s;
            loper++;
            }
            s ++;
        }
    *loper = 0;
}

void print_string(char * s){
    while(*s != 0){
        printf("%c", *s);
        s++;
    }
}

int main(void){
    char a[] = "8d'a7!<t-)>+. -)4h&!e9)b*( )j'(e)!4\n8g|'92o!43e5d/.' 2 3g*(e('d22a'(a25n'(";
    wis(a);
    printf("%s", a);
}
