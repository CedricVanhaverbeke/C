#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
	int *t;
	
	printf("n: ");
	scanf("%d",&n);
    t = (int*)malloc(n*sizeof(int));
    if ( t == NULL) {
       printf("malloc failed\n");
       return -1;
    } 
    
    for (i=0 ; i<n ; i++) {
       printf("getal %d: ",i+1);
       scanf("%d",&t[i]);
    }
    
    printf("De ingelezen getallen zijn:\n");
    for (i=0 ; i<n ; i++) {
       printf("%d ",t[i]);
    }

    /* let op!! onderstaande is niet ok!!
       programma crasht bij free(t)!! 
       Wel ok indien na t++ opnieuw t-- gedaan wordt 
	   of indien vooraf p = t en daarna free(p) */  
    t++;
    printf("%d",*t);
    
    free(t);
    return 0;
}



