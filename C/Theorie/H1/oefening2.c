#include <stdio.h>

void proc(int n) {
   if (n == 0) 
      printf("Start\t");
   else {
      proc(n-1);
      printf("%d\t",n);
   }
}

int main() {
   proc(3); 
   return 0;
}
