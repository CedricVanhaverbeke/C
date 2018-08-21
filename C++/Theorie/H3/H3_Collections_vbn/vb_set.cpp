#include <set>
#include <iostream>
using namespace std;

int main() {
    set<string> s;
    s.insert("peer");
    s.insert("banaan");  
    s.insert("kiwi"); 
    s.insert("appel");
    
    pair<set<string>::iterator, bool> ret = s.insert("banaan");
    s.insert(ret.first,"appelsien"); //max. efficiënt toevoegen
    cout << s.size() << endl;
    
    set<string>::iterator it = s.begin();
    while (it != s.end()) {
       cout << *it++ << endl;
    }
    
    string zoekwoord; 
    cout << "Wat moet ik zoeken? ";
    cin >> zoekwoord;
    cout << zoekwoord 
         << (s.count(zoekwoord) == 1 ? "" : " niet") 
         << " gevonden" << endl;
    
    s.erase("banaan");
    cout << s.size() << endl; 
    for (string woord : s)
       cout << woord << endl;

    it = s.find("Kiwi");
    if (it != s.end())
       s.erase(it);
    cout << s.size() << endl;   
    for (string woord : s)
       cout << woord << endl;
     
    return 0;
}
