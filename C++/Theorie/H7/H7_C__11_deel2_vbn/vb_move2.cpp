// vraag 1: ga na wat er gebeurt als de
// move-constructor en -operator in commentaar staan

// vraag 2: ga na wat er gebeurt als er een
// move-constructor/operator voorzien is, maar geen
// copy-constructor/operator

// vraag 3: ga na wat er gebeurt als er geen
// move/copy-constructor/operator voorzien is

#include <iostream>
#include <vector>
using namespace std;

class A {
   public:
   	  A();
      A(const vector<int> &);
	  A(const vector<int> &, int, int *);
      A(const A &);
      A(A &&);
      ~A();
      A& operator=(const A &);
      A& operator=(A &&);
      A operator*(int) const;
      void print() const;
      
   private:
      int grA;
      int *tabA;
      vector<int> vA;
};

A::A(const vector<int> &v,int i, int *p) : 
              vA(v), grA(i), tabA(nullptr) {
   if (grA > 0) {
   	   tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          tabA[i] = p[i];
   }
}

A::A() : grA(0),tabA(nullptr) {}  //en de vector?
A::A(const vector<int> &v) : A(v,0,nullptr) {}
A::A(const A &a) : A(a.vA, a.grA, a.tabA) {
	cout << "copy constructor" << endl;
};
A::A(A &&a) : vA(move(a.vA)), grA(a.grA), tabA(a.tabA) {
   cout << "move constructor" << endl;
   a.grA = 0;
   a.tabA = nullptr;
}
A::~A() {
   cout << "destructor A" << endl;
   delete[] tabA;
}
	  
A& A::operator=(const A& a) {
   cout << "= operator" << endl;
   if(this != &a) {
   	  vA = a.vA;
      delete[] tabA;
      grA = a.grA;
      if (grA > 0) {
   	     tabA = new int[grA];
         for(int i=0 ; i<grA ; i++){
            tabA[i] = a.tabA[i];
         }
      }
   }
   return *this;
}

A& A::operator=(A&& a) {
   cout << "move operator" << endl;
   if(this != &a) {
   	  vA = move(a.vA);
      delete[] tabA;
      grA = a.grA;
      tabA = a.tabA;
      a.grA = 0;
      a.tabA = nullptr;
   }
   return *this;
}

A A::operator*(int f) const {
   A res;
   if (grA > 0) {
   	   res.grA = grA;
   	   res.tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          res.tabA[i] = tabA[i] * f;   	
   }
   if (vA.size() > 0) {
      res.vA.reserve(vA.size());
      for (int i=0; i<vA.size(); i++)
         res.vA.push_back(vA[i] *f);
   }
   return res;
}

void A::print() const {
   for (int i=0 ; i<grA ; i++)
      cout << tabA[i] << "  ";
   cout << endl;
   for (int i: vA)
      cout << i << "  ";
   cout << endl;
}

int main () {
   A a3, a5, a6;
   int pA[4] = {12, 7, 16, 11};
   vector<int> v = {-3, -9, -15};
   A a1(v, 4, pA);
   cout << "a1.print();" << endl;
   a1.print();
 
   cout << endl << "A a2(a1);" << endl;  
   A a2(a1);
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a2.print();" << endl;
   a2.print(); 
   
   cout << endl << "a3 = a1;" << endl;
   a3 = a1;
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a3.print();" << endl;
   a3.print();      

   cout << endl << "A a4(move(a1));" << endl;
   A a4(move(a1));
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a4.print();" << endl;
   a4.print(); 

   cout << endl << "a5 = move(a2);" << endl;
   a5 = move(a2);
   cout << "a2.print();" << endl;
   a2.print(); 
   cout << "a5.print();" << endl;
   a5.print(); 
   
   cout << endl << "a6 = a3*2;" << endl;
   a6 = a3*2;
   cout << "a3.print();" << endl;
   a3.print(); 
   cout << "a6.print();" << endl;
   a6.print(); 
          
   return 0;
}

/*
vraag 1: als er geen move-constructor/operator is, 
         wordt de copy-constructor opgeroepen
vraag 2: indien wel move-constructor/operator, 
         maar geen copy-constructor/operator 
		 => error compiler: er worden geen automatische
		 copy-constructor/operator meer voorzien
vraag 3: indien noch copy/move-constructor: geen probleem
         => default copy/move
*/
