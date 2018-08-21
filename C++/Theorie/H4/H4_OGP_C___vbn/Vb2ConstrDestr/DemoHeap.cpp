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
 MyClass *a = new MyClass(1);
 for (int i=2 ; i<4 ; i++) {
	MyClass *b = new MyClass(i);
 }
 delete a;
 return 0;
}


