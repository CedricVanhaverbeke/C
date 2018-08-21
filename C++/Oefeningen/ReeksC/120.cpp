#include "containers.h"
#include <fstream>

using namespace std;

int main(void){
    set<int> regelnummers;
    vector<int> volgorde;
    map<int,string> bijbel;

    //Stream voor beide bestanden maken.
    ifstream ifs;
    //Eerst lijnen uitlezen:
    ifs.open("regelnummers.txt");
    if(!ifs.is_open()){
        cout << "Probleem bij openen bestand";
        return 1;
    } else {
        int regelnummer;
        ifs >> regelnummer;
        while(!ifs.fail()){
            regelnummers.insert(regelnummer);
            volgorde.push_back(regelnummer);
            ifs >> regelnummer;
        }
        if(!ifs.eof()){
            cout << "Probleem bij inlezen bestand";
            return 1;
        }
        ifs.close();
    }

    set<int>::iterator lit = regelnummers.begin();

    // Bijbel inlezen. Pas beginnen met inlezen vanaf de eerste lijn die moet ingelezen worden. Breek het lezen af na de laatste lijn
    ifs.open("nbible.txt");
    if(!ifs.is_open()){
        cout << "Probleem bij openen bestand";
        return 1;
    } else {
        string zin;
        getline(ifs, zin);
        int regelteller = 0;
        //Niets controleren als we nog niet op de juiste lijn zitten
        while(regelteller <= *(regelnummers.begin()) -1 ){
            getline(ifs, zin);
            regelteller++;  
        }
        //Stoppen wanneer we het einde van de tekst bereiekt hebben
        while(!ifs.fail() && regelteller <= *(regelnummers.end())){
            lit = regelnummers.begin();
            while(lit != regelnummers.end()){
                if(*lit == regelteller+1){
                    bijbel[*lit] = zin;
                }
                lit++;
            }
            regelteller++;
            getline(ifs, zin);
        }
        ifs.close();
    }

    //Uitschrijven van lijnen in juiste volgorde:
    for(int i = 0; i<volgorde.size(); i++){
        cout << bijbel[volgorde[i]] << endl;
    }

    return 0;
}