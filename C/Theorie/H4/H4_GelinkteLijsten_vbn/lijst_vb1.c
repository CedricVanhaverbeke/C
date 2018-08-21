#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;

struct knoop {
	int getal;
	knoop *next;   
};

knoop* maak_lijst();
void print_lijst(const knoop*);

int main() {
	knoop *lijst;
    printf("Geef reeks getallen in (stop met 0):\n");
	lijst = maak_lijst();
	printf("Reeks getallen zijn:\n");
    print_lijst(lijst);
	return 0;
}

knoop* maak_lijst() {
   knoop *l,*h;
   int getal;
   scanf("%d",&getal);
   if (getal == 0)
      l = 0;
   else {
      l = (knoop*) malloc(sizeof(knoop));
      h = l;
      h->getal = getal;
      scanf("%d",&getal);
      while (getal != 0) {
         h->next = (knoop*) malloc(sizeof(knoop));
         h = h->next;
         h->getal = getal;
         scanf("%d",&getal);
      }
      h->next = 0;
   }
   return l;
}

void print_lijst(const knoop *l) {
   while (l != 0) {
      printf("%d\n", l->getal);
      l = l->next;
   }
}

