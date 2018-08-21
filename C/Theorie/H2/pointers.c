#include <stdio.h>

int main(void){
    const int * * const * a;
    a++;
    //(*a)++; //Gaat niet
    (**a)++;
    //(***a)++; //Gaat niet
}
