#include <memory>
#include <iostream>
using namespace std;

/* Hier moet je opletten dat je rekening houdt dat een nullptr niet uitgeschreven kan worden */
void schrijf(const unique_ptr<string> *  s, int aantal){
    cout<<endl;
        for(int i=0; i<aantal-1; i++){
            if(s[i]){
                cout<<*(s[i])<<" - ";
            }
        }
    if(s[aantal-1]){
        cout<<*(s[aantal-1]);
    }
}

/* Hier move je de pointers 1 naar voor. Opletten op het einde wel: als je het laatste element wil verwijderen
   zal s[i+1] buiten de array zitten en da's een probleem :). Deze situatie behandelen we dus apart in de else if */
void verwijder(unique_ptr<string> * s, int aantal, int volgnr){
    if(volgnr < aantal - 1){
        for(int i = volgnr; i < aantal-2; i++){
            s[i] = move(s[i+1]);
        }
    } else if(volgnr == aantal - 1){
        s[volgnr].reset();
    }
}

int main(){
    unique_ptr<string> pnamen[]={make_unique<string>("Rein"),
    make_unique<string>("Ada"),
    make_unique<string>("Eppo")};
    schrijf(pnamen,3);
    verwijder(pnamen,3,0);
    schrijf(pnamen,3);
    return 0;
}