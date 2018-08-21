#include "containers.h"

int main(void){
    map<char, set<string>> map;
    string s;
    cin >> s;
    while(s != "STOP"){
        map[s[0]].insert(s);
        cin >> s;
    }
    cout << endl << "Geef nu een letter in, en ik vertel je hoeveel woorden met die letter beginnen" << endl;
    char c;
    cin >> c;
    cout << endl << map[c].size();
}