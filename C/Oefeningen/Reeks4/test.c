#include <stdio.h>
#include <string.h>

int main(void){
    char woord[8];
    fgets(woord, 9, stdin);
    printf("%s", woord);
    printf("%d", (int)strlen(woord));
    return 0;
}
