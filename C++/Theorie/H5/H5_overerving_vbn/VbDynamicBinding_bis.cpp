// VbDynamicBinding_bis.cpp

// <<-operator werkt nu prima, aangezien deze 
// de private/protected virtuele methode schrijf oproept

#include <iostream>
#include <string>
using namespace std;

class Persoon {
   private:
      string naam;
   protected:
      virtual void print(ostream &) const;   
   public:
      Persoon(const string &nm="");    
      friend ostream& operator<<(ostream&,const Persoon&);
      
};  // Persoon

class Student : public Persoon {
   private:
      string klascode;
      void print(ostream &) const;
   public:
      Student(const string &nm="", const string &kl="");
};  // Student

class Leerkracht : public Persoon {
   private:
      string vakgroep;
      virtual void print(ostream &) const;
   public:
      Leerkracht(const string &nm="", const string &vg=""); 
};  // Leerkracht

Persoon::Persoon(const string &nm) : naam(nm) {}

void Persoon::print(ostream & os) const {
   os<<naam;
}

ostream& operator<<(ostream& os,const Persoon &p) {
	p.print(os);
	return os;
}

Student::Student(const string &nm, const string &kl) : 
            Persoon(nm),klascode(kl) {}

void Student::print(ostream &os) const {
   Persoon::print(os);
   os<<" zit in klas "<<klascode;
}

Leerkracht::Leerkracht(const string &nm, const string &vg) : 
                Persoon(nm),vakgroep(vg) {}

void Leerkracht::print(ostream &os) const {
   Persoon::print(os);
   os<<" uit vakgroep "<<vakgroep;
}

int main() {
   Persoon p("Leo");
   cout << p << endl;   
   Student s("Jan","1Ba3");
   cout << s << endl;
   Leerkracht l("Marc","EA20");
   cout << l << endl;
  
   cout << "p = l;" << endl; 
   p = l;
   cout << p << endl;
   
   cout << "Persoon *pps=&s, *ppl=&l;" << endl;
   Persoon *pps=&s, *ppl=&l;
   cout << *pps << endl;
   cout << *ppl << endl;
   
   cout << "Persoon *ppl2 = new Leerkracht(\"Els\",\"Talen\");" << endl;
   Persoon *ppl2 = new Leerkracht("Els","Talen");
   cout << *ppl2 << endl;
   delete ppl2;
   
   return 0;
}
