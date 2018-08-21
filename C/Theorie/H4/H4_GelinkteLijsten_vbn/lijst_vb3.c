#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;

struct knoop {
	int getal;
	knoop *next;   
};

knoop* maak_lijst();
void print_lijst(const knoop*);
void verwijder_element(knoop**,int);

int main() {
    knoop *lijst = maak_lijst();
    printf("volledige lijst:\n");
    print_lijst(lijst);
    verwijder_element(&lijst,4);
    printf("\n4 weg:\n");   
    print_lijst(lijst); 
	verwijder_element(&lijst,1); 
	printf("\n1 weg:\n");
	print_lijst(lijst); 
	verwijder_element(&lijst,7); 
	printf("\n7 weg:\n");
	print_lijst(lijst);
	verwijder_element(&lijst,7); 
	printf("\n7 weg:\n");
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

void verwijder_element(knoop **lijst, int getal) {
   knoop *m,*h;
   if (*lijst != 0) {
      if ((*lijst)->getal == getal) {
         m = *lijst;
         *lijst = (*lijst)->next;
         free(m);
      }
      else {
         h = *lijst;
         while (h->next!=0 && h->next->getal!=getal)
            h = h->next;
         if (h->next != 0) {
            m = h->next;
            h->next = m->next;
            free(m);
         }
      }
   }	
}

