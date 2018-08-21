#include "breuk.h"


int mijn_ggd(int a, int b){
    if(a < 0 || b < 0){
        return mijn_ggd(abs(a), abs(b));
    }
    if(a < b){
        return mijn_ggd(b,a);
    }
    if(b == 0){
        return a;
    }
    return mijn_ggd(b,a%b);
}

void Breuk::normaliseer(){
    if(noemer < 0){
        noemer *= -1;
        teller *= -1;
    } 
    int deler = mijn_ggd(teller,noemer);
    noemer /= deler;
    teller /= deler;
}

ostream & operator<<(ostream & out, const Breuk & b){
    if(b.noemer != 1){
        out << b.teller << "/" << b.noemer;
    } else{
        out << b.teller;
    }
    return out;
}

istream & operator>>(istream & in, Breuk & b){
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
    b.teller = teller;
    b.noemer = noemer;
    return in;
}

Breuk Breuk::operator+(const Breuk & b) const {
    Breuk tmp;
    int ggd = mijn_ggd(b.noemer, noemer);
    tmp.teller = (teller * b.noemer + b.teller * noemer);
    tmp.noemer = (noemer * b.noemer);
    tmp.normaliseer();
    return tmp; 
}

Breuk Breuk::operator-() const {
    Breuk tmp(*this); // copyconstructor
    tmp.teller *= -1;
    // Of sneller return Breuk(teller * -1; noemer);
    return tmp;
}

Breuk Breuk::operator-(const Breuk & b) const {
    Breuk tmp; //Niet vergeten tmp() werkt hier niet. Default-constructor kan je niet zelf oproepen
    tmp.teller = (teller * b.noemer - b.teller * noemer);
    tmp.noemer = (noemer * b.noemer);
    return tmp;
}

Breuk & Breuk::operator+=(const Breuk & b) {
    teller = (teller * b.noemer + b.teller * noemer);
    noemer = (noemer * b.noemer);
    normaliseer();
    return *this;
}

Breuk & Breuk::operator-=(const Breuk & b){
    teller = (teller * b.noemer - b.teller * noemer);
    noemer = (noemer * b.noemer);
    normaliseer();
    return *this;
}

//Dit is de prefix-operator.
/* Waarom?
++a geeft hetzelfde object terug waar +1 mee is gedaan. Vandaar dus de &. 
a++ geeft niet hetzelfde object terug. Je maakt een kopie van a, deze geef je terug. De echte a doe je dan + 1*/
Breuk & Breuk::operator++(){
    teller+= noemer;
    return *this;
}

//postfix-operator
Breuk Breuk::operator++(int x){
    Breuk temp(*this);
    teller += noemer;
    return temp;
}

bool Breuk::operator==(const Breuk & b) const {
    return (teller == b.teller && noemer == b.noemer);
}

bool Breuk::operator!=(const Breuk & b) const {
    return (teller != b.teller || noemer != b.noemer);
}

string is_stambreuk(Breuk & b){
    if(b.noemer == 1){
        return "jup";
    }
    return "nee";
}

Breuk Breuk::operator+(int x) const{
    Breuk tmp(teller + x * noemer, noemer);
    tmp.normaliseer();
    return tmp;

}

//Friend functie omdat de operator begint vanaf de x
Breuk operator+(int x, const Breuk & b){
    Breuk tmp(b.teller + x*b.noemer, b.noemer);
    tmp.normaliseer();
    return tmp;
}

bool Breuk::operator<(const Breuk & b) const{
    return(teller * b.noemer < b.teller * noemer);
}