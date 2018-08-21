#include <iostream>
using namespace std;

class MyClass {
   private:
      int i;
      
   public:
      MyClass(int i);
      ~MyClass() {
         cout << "Destructor object " << i <<endl;
      }
};

MyClass::MyClass(int i) {
   cout << "Constructor object "<< i << endl;
   this->i = i;
}

int main() {
 MyClass a(1);
 for (int i=2 ; i<4 ; i++) {
	MyClass b(i);
 }
 int k=0;
 for (MyClass c(4) ; k<2 ; k++) {
	cout << k << endl;
 }
 return 0;
}


