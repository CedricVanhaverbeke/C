#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "bestand_niet_lang_genoeg.cpp"
using namespace std;


string regel_uit_bestand(const string & bestand, int volgnr){
    ifstream ifs;
    ifs.open(bestand);

    if(!ifs.is_open()){
        throw bestand;
    }

    int lijnnr = 0;
    string lijn;
    getline(ifs, lijn);
    if(lijn != "VERHAAL"){
        // Zeer belangrijk, je kan dus van eens string een c_string maken
        throw lijn.c_str();
    }
    while(!ifs.fail() && lijnnr != volgnr - 1){
        lijnnr++;
        getline(ifs, lijn);
    }
    if(lijnnr != volgnr - 1){
        throw bestand_niet_lang_genoeg(bestand);
    }
    return lijn;
}

int main(void){
    vector<string> bestandsnamen({"niks","een","twee","drie","vier",
    "vijf","zes","zeven","acht","negen","tien","elf","twaalf"});
    vector<int> nrs({8,5,2,10,7,3,8,4,1,1,6,2,4});
    
    string bestanden_niet_gevonden = "";
    string bestanden_niet_lang_genoeg = "";
    string eerste_woorden = "";
    for(int i=0; i<bestandsnamen.size(); i++){
        try {
             cout << regel_uit_bestand(bestandsnamen[i]+".txt",nrs[i]) << endl;
        }
        catch(const string & s){
            bestanden_niet_gevonden += s + " ";
        } 
        catch(const char * s){
            eerste_woorden += string(s) + " ";
        }
        catch(const bestand_niet_lang_genoeg & exc){
            bestanden_niet_lang_genoeg += string(exc.what());
        }
    }
    cout<<endl<<endl<<"BESTANDEN NIET GEVONDEN:"<<endl;
    cout<<bestanden_niet_gevonden;
    cout<<endl<<"BESTANDEN NIET LANG GENOEG:"<<endl;
    cout<<bestanden_niet_lang_genoeg<<endl;
    cout<<endl<<"BESTANDEN ZONDER STARTWOORD 'VERHAAL':"<<endl;
    cout<<"dit waren de woorden die er wel als eerste stonden:"<<endl<<endl;
    cout<<eerste_woorden<<endl<<endl;
return 0;
}