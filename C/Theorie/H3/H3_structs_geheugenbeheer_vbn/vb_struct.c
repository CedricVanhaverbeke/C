#include <stdio.h>

typedef struct {
   double x;
   double y;
} punt;

int main() {
    punt p1;
	punt p2 = {3.5,-2.9};
	punt p3 = {7.2};
    punt t1[5] = {{1.2,-1.2},{5.1,4.6}};
    punt t2[3] = {8};		
    int i;
    
    p1.x = 3.5;
    printf("y-coord p1: ");
    scanf("%lf",&p1.y);
    printf("p1 = {%.2lf,%.2lf}\n",p1.x, p1.y);
    printf("p2 = {%.2lf,%.2lf}\n",p2.x, p2.y);
    printf("p3 = {%.2lf,%.2lf}\n",p3.x, p3.y);
    for (i=0 ; i<5 ; i++) 
      printf("t1[%d] = {%.2lf,%.2lf}\n",i,t1[i].x,t1[i].y);
    for (i=0 ; i<3 ; i++) 
      printf("t2[%d] = {%.2lf,%.2lf}\n",i,t2[i].x,t2[i].y);
    if (p1.x == p2.x && p1.y == p2.y) 
       printf("p1 en p2 gelijk");
    
    return 0;
}
