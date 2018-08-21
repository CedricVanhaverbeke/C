#include <stdio.h>
#include <limits.h>

const int * kleinste(const int * t, int n){
    const int *kl;
    int i;
    kl = t;

    for(i=1; i<n; i++){
        if(t[i] < *kl){
            kl = t+i;
        }
    }

    return kl;
}


int main(void){
    int array[4] = {69, 2, 15, 4};
    const int * kl;

    kl = kleinste(array, 4);

    printf("%d", *kl);
        
    return 0;
}
