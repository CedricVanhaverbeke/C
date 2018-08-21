#include <stdio.h>

int main(void){
    int i;
    for(i=0; i<=64; i++){
        printf("%4d %4o %4x \n", i, i, i);
    }
}
