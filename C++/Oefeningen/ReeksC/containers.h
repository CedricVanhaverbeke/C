#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <vector>

using namespace std;

template <class T>
ostream & operator<<(ostream & out,vector<T> & v){
    if(v.size() != 0){
            out << "[ " << v[0] << " |";
    for(int i = 1; i<v.size() -1; i++){
        out << " " << v[i] << " |";
    }
    out << " " << v[v.size()-1];
    out << " ]" << endl;
    }
    return out;
}

template <class T>
ostream & operator <<(ostream & out, const set<T> & s){
    typename set<T>::iterator it = s.begin();
    typename set<T>::iterator hulp = s.end(); // end() - 1 werkt niet. Zie volgende lijn
    hulp--; // Hulp staat nu op de laatste plaats (end is voorbij de laatste plaats). Nodig om de komma's te stoppen bij het laatste element
    out << "{ ";
    while(it != hulp){
        out << *it << ", ";
        it++;
    }
    out << *it << " }";
    return out;
}

// s moet hier een kopie zijn aangezien we de echte stack niet willen aanpassen
template <class T>
ostream & operator<<(ostream & out, stack<T> s){
    out << endl << "STACK: " << endl;
    while(!s.empty()){
         out << s.top() << endl;
         // De stapel werkt niet zoals Java. Je krijgt geen referentie terug naar het element dat verwijderd is in C++
         // In Java wel, daarom moet je dus top printen.
         s.pop();
    }
    return out;
}


template <typename K, typename V>
ostream & operator<<(ostream & out, map<K,V> & map){
    // De dubbele puntjes voor map moeten hier. Waarom begrijp ik niet. Nu ja, het werkt. In de vboplossing staan ze niet.
    typename ::map<K,V>::iterator it = map.begin();
    while(it != map.end()){
        out << it->first << "->" << it->second << " ";
        it++;
    }
    out << endl;
    return out;
}