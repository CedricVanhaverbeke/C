#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(void){
    ifstream ifs;
    char c;
    int frequentie[26];
    ifs.open("lord.txt");
    if(!ifs.is_open()){
        cout << "Something went terribly wrongk";
    } else {
        ifs >> c;
            while( !ifs.fail() ){
                if(c >= 'a' && c <= 'z'){
                    frequentie[c - 'a']++;
                }
                ifs >> c;
            }
            if(!ifs.eof()){
                cout << "Something went wrong";
            }
        }
    for(int i = 0; i<26; i++){
        char c = 'a' + i;
        cout << c << ": " << frequentie[i] << endl;
    }
    return 0;
}