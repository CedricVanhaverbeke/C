#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Dit werkt niet al lijkt het mij wel juist */

struct Persoon{
    string voornaam;
    string naam;
    int leeftijd;
    Persoon(const string & v, const string & n, int l){
    voornaam = v; naam = n; leeftijd = l;
    }
};

ostream& operator<<(ostream & out, const Persoon & p){
    out<<p.naam <<" "<<p.voornaam<<" ("<<p.leeftijd<<")";
    return out;
}

class Groep : public vector<Persoon>{
public:
Persoon geef_extremum(function<bool (const Persoon &, const Persoon&)>); 
};

Persoon Groep::geef_extremum(function<bool (const Persoon &, const Persoon&)> func){
    int index = 0;
    for(int i = 1; this->size(); i++){
        if(func( (*this)[i],(*this)[index] )){
            index = i;
        }
    }
    return (*this)[index];
}

int main(){
    Groep gr;
    gr.push_back(Persoon("Ann","Nelissen",12));
    gr.push_back(Persoon("Bert","Mertens",22));
    gr.push_back(Persoon("Celle","Lauwers",55));
    cout<<"Eerste qua naam: " << gr.geef_extremum([](const Persoon & a, const Persoon & b)->bool {
        return a.naam < b.naam;
    });

    cout<<"Eerste qua voornaam: " << gr.geef_extremum([](const Persoon & a, const Persoon & b)->bool{
        return a.voornaam < b.voornaam;
    });
    cout<<"Jongste: " << gr.geef_extremum([](const Persoon & a, const Persoon & b)->bool{
        return a.leeftijd < b.leeftijd;
    });
    cout<<"Oudste: " << gr.geef_extremum([](const Persoon & a, const Persoon & b)->bool{
        return a.leeftijd > b.leeftijd;
    });

    return 0;
}