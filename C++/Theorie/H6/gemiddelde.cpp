// Mijn versie van de oefening in de theorie

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int gemiddelde(string s){
    ifstream ifs;
    ifs.open(s);
    if(!ifs.is_open()){
        throw "Fout bij openen van bestand";
    }
    int getal;
    int aantal = 0, som = 0;
    ifs >> getal;
    while(!ifs.fail()){
        aantal++;
        som+= getal;
        ifs >> getal;
    }

    if(!ifs.eof()){
        throw "Probleem bij inlezen";
    }

    if(aantal == 0){
        throw "Leeg bestand";
    }

    return som / aantal;
} 

int main(void){
    try {
        int gem = gemiddelde("getallen.txt");
        cout << gem;
    }
    // Vergeet hier niet de const.
    catch(const char * s) {
        cout << s;
    }
    catch(...){
        cout << "Andere fout";
    }

    return 0;
}