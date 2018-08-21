#include <iostream>
#include <string>
using namespace std;

class Student {
   public: 	  
	  Student(int, const string &, int, const int *);	  
      Student(int nr, const string &nm);
      Student();
      ~Student(); 
      void print() const;
      void wijzig_punt(int, int);
      void wijzig_naam(const string &);
      
   private:
      int stnr;
      string naam;
      int aantalPunten;
      int *punten;
};

Student::Student(int nr, const string &nm, int aant, const int *ptn) {
   stnr = nr; 
   naam = nm;
   aantalPunten = aant;
   if (aantalPunten > 0) {
   	   punten = new int[aantalPunten];
       for(int i=0 ; i<aantalPunten ; i++)
          punten[i] = ptn[i];
   }
   else
      punten = nullptr;
}

Student::Student(int nr, const string &nm) 
   : Student(nr,nm,0,nullptr) {}
Student::Student() : Student(0,"",0,nullptr) {}

Student::~Student() {
   delete[] punten;
}

void Student::print() const {
   cout << stnr << ' ' << naam << '\t';
   for (int i=0 ; i<aantalPunten ; i++)
      cout << punten[i] << "  ";
   cout << endl;
}

void Student::wijzig_punt(int index, int score) {
   if (index < aantalPunten)
      punten[index] = score;
}

void Student::wijzig_naam(const string &nm) {
   naam = nm;
}

int main () {  
   int ptn[4] = {12, 7, 16, 11};
   Student s1(20021923,"Jef Bracke",4,ptn);
   Student s2(20021005,"Tom Put");
   s1.print();
   s2.print();
   Student s3(s1);
   s3.wijzig_naam("Leo Maes");
   s3.wijzig_punt(1,10);
   s3.print();
   s1.print();  
   return 0;
}
