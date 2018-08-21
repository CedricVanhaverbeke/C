#include <iostream>
#include <memory>
using namespace std;

void write_pointer(shared_ptr<int> p) {
   if (p) 
     cout << *p << endl; 
   else 
     cout << "empty\n";
}

int main () {
  shared_ptr<int> p1 = make_shared<int>(101);
  shared_ptr<int> p2, p3; 
  
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 
  
  p2 = p1;
                        
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 

  (*p2)++;
  cout << "p1: ";
  write_pointer(p1);
  cout << "p2: ";
  write_pointer(p2);
  
  p3 = move(p2);
  cout << "p1: ";
  write_pointer(p1);
  cout << "p2: ";
  write_pointer(p2);
  cout << "p3: ";
  write_pointer(p3);
  
  p3.reset();
  cout << "p1: ";
  write_pointer(p1);
  cout << "p2: ";
  write_pointer(p2); 
  cout << "p3: ";
  write_pointer(p3);
  
  return 0;
}
