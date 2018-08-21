#include "containers.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ifstream ifs;
    ifs.open("bible_stop.txt");
    // Vector van mappen maken met mappen zoals in de vorige oefening
    vector<map<char, set<string>>> v;

    if(!ifs.is_open()){
        cout << "Something went terribly wrongk";
        return 1;
    } else {
        string woord;
        ifs >> woord;
    
        /* Hier komt het erop neer dat een vector moet groeien voor je er iets insteekt, tenzij je met psuh_back werkt, maar dat gaat hier niet. */
        while(!ifs.fail()){
            if(v.size() < woord.size()+1){
                v.resize(woord.size()+1);
            }
            v[woord.size()][woord[0]].insert(woord);
            ifs >> woord;
        }
        
        if(!ifs.eof()){
            cout << "Something went terribly wrongk";
            return 1;
        }
    }
    
    // Uitschrijven van de vector. We kunnen deze printen met containers.h
    /*for(int i = 0; i<v.size();i++){
        cout << v[i];
        cout << endl;
    }*/

    cout << endl << "Geef nu een woord in en ik zal alle woorden printen die met hetzelfde karakter beginnen en dezelfde lengte hebben:" << endl;
    string woord;
    cin >> woord;

    cout << v[woord.size()][woord[0]];

    return 0;    
}
