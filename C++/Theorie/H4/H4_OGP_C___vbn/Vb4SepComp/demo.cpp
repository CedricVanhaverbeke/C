#include "Student.h"

int main () {
   int ptn[4] = {12, 7, 16, 11};
   Student s1(20021923,"Jef Bracke",4,ptn);
   Student s2(20021005,"Tom Put");
   s1.print();
   s2.print();
   Student s3(s1);
   s3.wijzig_punt(1,10);
   s3.wijzig_naam("Leo Maes");
   s3.print();
   s1.print();  
   return 0;
}
