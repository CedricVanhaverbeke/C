#include <stdio.h>
#include <string.h>

char * alfab_kleinste(char ** voornamen, int n){
    int i;
    char * kl = voornamen[0];
    for(i=1; i<n; i++){
        if( strcmp(kl, voornamen[i]) > 0 ){
            kl = voornamen[i];
        }
    }
    return kl;
}

int main(int argc, char ** argv){
    int i;
    char * kleinste;
    if(argc == 1){
        printf("Dag allemaal!");
    } else {
        kleinste = alfab_kleinste(argv + 1, argc - 1);
        printf("Dag %s", kleinste);
    }
    return 0;
}
