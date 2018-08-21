#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char ** argv){
    cout << "test";
    const int aantal = argc - 1;
    ifstream ifs[aantal];
    for(int i = 0; i < aantal; i++){
        cout << argv[i+1];
        ifs[i].open(argv[i+1]);
        if(!ifs[i].is_open()){
            cout << "Something went wrong";
            return 1;
        }
    }  
    
    int teller = 0;
    ofstream of;
    of.open("mix.txt");
    if(!of.is_open()){
        cout << "Something went wrong";
        return 1; 
    } else {
        string s;
        bool nofail = true;
        getline(ifs[teller], s);
        if(ifs[teller].fail()){
            nofail = false;
        }
        cout << s;
         while(nofail){
            for(int i = 0; i<aantal; i++){
                if(ifs[i].fail()){
                    nofail = false;
                }
            }
            teller = (teller + 1) % aantal;
            of << s;
            getline(ifs[teller], s);
        }
        if(!ifs[teller].eof()){
            cout << "Something went wrong";
            return 1; 
        } else {
            cout << "Bestanden zonder problemen ingelezen";
        } 
    }
    return 0; 
}