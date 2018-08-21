// DemoDestructor2.cpp
// virtuele destructor

#include <iostream>
using namespace std;

class Basis {
   protected:
   	  int i;
   public:
      Basis(int _i) : i(_i) {
         cout<<"constructor van basis "<< i << endl;
      }
      virtual ~Basis() {
         cout<<"destructor van basis "<< i << endl;
      }
};
 
class Afgeleid : public Basis {
   public:
      Afgeleid(int i) : Basis(i) {
         cout<<"constructor van afgeleid " << i << endl;
      }
      virtual ~Afgeleid() {
         cout<<"destructor van afgeleid " << i << endl;
      }
};

int main() {
   Basis b1(1);
   Afgeleid a(2);
   
   Basis *b2 = new Basis(3);
   delete b2;
   
   Basis *b3 = new Afgeleid(4); 
   delete b3;
      
   return 0;
}

