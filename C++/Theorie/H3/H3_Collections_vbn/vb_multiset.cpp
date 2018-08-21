#include <set>  //niet <multiset>!!!
#include <iostream>
using namespace std;

int main() {
    multiset<string> ms;
    ms.insert("peer");
    ms.insert("banaan");  
    ms.insert("kiwi");
    ms.insert("appel"); 
    ms.insert("banaan");
    ms.insert("peer"); 
    cout << ms.size() << endl;
    cout << ms.count("banaan") << endl;
    multiset<string>::iterator it = ms.begin();
    while (it != ms.end()) {
       cout << *it++ << endl;
    }

    it = ms.find("banaan");
    if (it != ms.end()) 
       ms.erase(it);
    cout << ms.size() << endl;   
    for (string s : ms) {
       cout << s << endl;
    }
    
    ms.erase("peer");
    cout << ms.size() << endl;   
    for (string s : ms) {
       cout << s << endl;
    }
    
    return 0;
}
