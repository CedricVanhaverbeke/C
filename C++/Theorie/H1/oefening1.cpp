#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>



using namespace std;

int main(void){
    ofstream of;
    of.open("tekst.txt", ios::app);
    if(of.is_open()){
        for(int i = 0; i < 5; i++){
            string s;
            getline(cin, s);
            of << s << endl;
        }
        of.close();
    }

}