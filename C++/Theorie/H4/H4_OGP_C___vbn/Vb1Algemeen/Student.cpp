#include <iostream>
#include <string>
using namespace std;

class Student {
   public:
      Student();
	  Student(int nr, const string &nm, 
	          int aant = 0, const int *ptn = nullptr);
      ~Student();
      void print() const;
      
   private:
      int stnr;
      string naam;
      int aantalPunten;
      int *punten;
};

Student::Student(int stnr, const string &nm, int aant, const int *ptn) {
   this->stnr = stnr; 
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

Student::Student() {
   stnr = 0; //niet automatisch 0!!!
   aantalPunten = 0;
   punten = nullptr;
   //naam is wel leeg (defaultconstructor van string is opgeroepen)
}

Student::~Student() {
   delete[] punten;
}

void Student::print() const {
   cout << stnr << ' ' << naam << '\t';
   for (int i=0 ; i<aantalPunten ; i++)
      cout << punten[i] << "  ";
   cout << endl;
}

int main () {
   int ptn[4] = {12, 7, 16, 11};
   Student s1(20021923,"Jef Bracke",4,ptn);
   Student s2(20021005,"Tom Put");
   Student s3;   // geen () toevoegen!!!
   s1.print();
   s2.print();
   s3.print();
   return 0;
}

/*
Opmerking: programma crasht indien bij constructor 
slechts 3 argumenten meegegeven worden.
Beter: 3 verschillende constructoren voorzien (0,2,4 parameters) 
en geen default parameters gebruiken 
(zie volgende versie)
 */
