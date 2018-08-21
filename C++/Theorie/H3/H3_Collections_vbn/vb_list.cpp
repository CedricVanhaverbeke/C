#include <iostream>
#include <list>
using namespace std;

struct punt {
   int x, y;
};

int main() {
   punt p1 = {4,7}, p2 = {2,1},
        p3 = {0,8}, p4 = {5,3};
   
   list<punt> l;
   l.push_back(p1);
   l.push_front(p2);
   
   list<punt>::iterator it = l.begin();
   while (it != l.end()) {
         cout << it->x << " " 
              << (*it).y << endl;
         it++;
   }
   
   it = l.begin();
   it++;
   l.insert(it,p3);
   l.insert(it,p4);
   
   for (punt p : l )
      cout << p.x << " " << p.y << endl;
   
   return 0;
}
