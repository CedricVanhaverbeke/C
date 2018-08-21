#include <stdio.h>
#include <math.h>

float * plaats_van(float * t, int n, float getal){
    int i = 1;
    while(i<n && fabsf(*t - getal) > 0.0001){
        i++;
        t++;
    }
    if(i < n){
        return t;
    } else {
        return 0;
    }
}

void plaats_pointer_op_getal(float ** ptr, float * t, float getal){
    *ptr = plaats_van(t,4,getal);
}

void print_tabel(const float * t, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%.2f ", *(t+i));
    }
    printf("\n");
}

int main(void){
    float t[] = {2.3 , 6.9, 8.5, 9.3};
    float * waarde = plaats_van(t, 4, 6.9);

    if(waarde == NULL){
        printf("1: De waarde bevond zich niet in de tabel\n");
    } else {
        printf("%f\n", *waarde);
    }

    
    plaats_pointer_op_getal(&waarde, t, 8.5);
    if(waarde == NULL){
        printf("2: Het getal bevond zich niet in de tabel\n");
    } else {
        *waarde *=2;
    }

    print_tabel(t,4);

    return 0;
}
