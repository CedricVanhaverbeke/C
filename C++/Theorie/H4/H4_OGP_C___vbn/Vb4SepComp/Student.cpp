#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(int nr, const string &nm, int aant, int *ptn) {
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

Student::Student(const Student &st) 
   : Student(st.stnr, st.naam, st.aantalPunten, st.punten) {}
Student::Student(int nr, const string &nm) 
   : Student(nr,nm,0,nullptr) {}
Student::Student() : Student(0,"",0,nullptr) {}

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
