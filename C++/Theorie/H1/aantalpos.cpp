#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int aantalpositief(string naam){
    ifstream ifs;
    int teller = 0;
    ifs.open(naam);
    if(ifs.is_open()){
        int d;
        ifs >> d;
        while(!ifs.fail()){
            if(d > 0){
                teller++;
            }
            ifs >> d;
        }
        if(!ifs.eof()){
            cout << "Something terrible must've happened";
        }
    } else {
        cout << "The file is kaput";  
    }
    return teller;
}

int main(void){
    int i = aantalpositief("bestand.txt");
    cout << i;
    return 0;
}