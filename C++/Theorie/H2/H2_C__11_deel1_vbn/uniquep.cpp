#include <iostream>
#include <memory>
using namespace std;

void write_pointer(const unique_ptr<int> &p) {
   if (p) 
     cout << *p << endl; 
   else 
     cout << "empty\n";
}
//merk op: unique pointers mogen nooit by value 
//doorgegeven worden!!

int main () {
  unique_ptr<int> p1(new int(101)), p2;
  //p2 = unique_ptr<int>(new int(202)); 
  p2 = make_unique<int>(202);
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 
  
  // FOUT: 
  // p2 = p1;
  
  p2.swap(p1);
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 
    
  p2 = move(p1);                      
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 

  (*p2)++;
  cout << "p2: ";
  write_pointer(p2);
  
  p2.reset();
  cout << "p2: ";
  write_pointer(p2); 
  
  //opmerking: gebruik unique_ptr NIET om naar
  //iets te verwijzen dat reeds bestaat!
  //dan kan problemen opleveren
  //onderstaande code is dus af te raden (=NIET goed)
  int getal = 5;
  unique_ptr<int> p3 = unique_ptr<int>(&getal);
  cout << *p3;

  return 0;
}
