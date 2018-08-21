#include <iostream>
#include <fstream>
#include <string> // nodig bij het inlezen van een breuk
#include <sstream> // vergelijk met Scanner(String) in Java
#include <cmath> // abs berekent absolute waarde van een int (fabs is voor double)
#include <set>

using namespace std;

int main(void){
    string test; cin >> test;
    stringstream ss; ss << test;
    bool noemeraanwezig = true;
    if(test.find("/") == string::npos){
        noemeraanwezig = false;
    }
    int teller; char streep;int noemer = 1;
    if(noemeraanwezig){
        ss >> teller;
        ss >> streep;
        ss >> noemer; 
    } else {
        ss >> teller;
    }
    cout << "teller: " << teller << " en noemer: " << noemer;
    return 0;
}