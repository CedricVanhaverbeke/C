#include <stdio.h>

int main(int argc, char ** argv){
    int i;
    if(argc == 1){
        printf("Dag allemaal!");
    } else {
        for(i=0; i<argc; i++){
            printf("Dag %s\n", argv[i]);
        }
    }
}
