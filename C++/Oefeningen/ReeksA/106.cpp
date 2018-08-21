#include <iostream>
#include <string>

using namespace std;

typedef struct Persoon Persoon;
struct Persoon {
    int leeftijd;
    int lengte;
    string naam;
};

template <class T>
T grootste(T * array, int lengte){
    T grootste = array[0];
    for(int i = 1; i < lengte; i++){
        if(grootste < array[i]){
            grootste = array[i];
        }
    }
    return grootste;
}

void initialiseer(Persoon & persoon, string naam, int leeftijd, int lengte){
    persoon.naam = naam;
    persoon.leeftijd = leeftijd;
    persoon.lengte = lengte;
}

void print(const Persoon & persoon){
    cout << persoon.naam << " is " << persoon.leeftijd << " jaar en is " << persoon.lengte / 100 << "m" << persoon.lengte % 100 << endl;
}

int main(void){
    double getallen[5] = {5.5,7.7,2.2,9.9,9.8};
    string woorden[3] = {"geloof","hoop","de liefde"};
    cout << grootste(getallen,5) << endl;
    cout << "De grootste van de drie is " << grootste(woorden,3) << "." << endl;
    
    Persoon personen[3];
    initialiseer(personen[0], "Samuel", 12, 152);
    initialiseer(personen[1], "Jente", 22, 181);
    initialiseer(personen[2], "Idris", 42, 173);

    for(int i = 0; i < 3; i++){
        print(personen[i]);
    }
}