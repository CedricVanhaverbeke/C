#include <iostream>
#include <fstream>
#include <vector>
#include "figuren.h"

class Blokkendoos : vector<unique_ptr<Figuur>>{
    private:
    unique_ptr<Figuur> max_opp;
    void schrijf(ostream&)const;
    public:
    Blokkendoos();
    Blokkendoos(const string & bestandsnaam);
    unique_ptr<Figuur> geef_figuur_met_grootste_oppervlakte();
    void push_back(unique_ptr<Figuur>&& figuur);
    friend ostream& operator<<(ostream& out, const Blokkendoos& l){
    l.schrijf(out);
    return out;
    }
};

// Die && is blijkbaar omdat je movet met de move constructor. Zie zijn definitie A :: A (A && a)
void Blokkendoos::push_back(unique_ptr<Figuur>&& figuur){
    if(this->max_opp == 0){
        max_opp = move(figuur);
    } else {
        //Niet vergeten: Je kan de methodes oproepen van de klasse waar je van erft door klassenaam vooraan te schrijven
        //Hier voegen we onze  figuur toe
        vector<unique_ptr<Figuur>>::push_back(move(figuur));
        // Controleren of de oppervlakte werkelijk groter is dan de gegeven opp
        if(operator[](this->size()-1)->oppervlakte() > this->max_opp->oppervlakte()){
            //We gaan dus de max_opp en de nieuwe Figuur niet allebei opslaan in de vector
            max_opp.swap( operator[](this->size()-1) );
        }
    }
}

unique_ptr<Figuur> Blokkendoos::geef_figuur_met_grootste_oppervlakte(){
    // Moven om later te kunnen teruggeven
    unique_ptr<Figuur> max = move(this->max_opp);

    // We bepalen nu de nieuwe maximale waarde, en gaan van achter naar voor zodat de laatste plaats 
    // Wegkan met resize()
    unique_ptr<Figuur> newmax = move(operator[](this->size() - 1));
    for(int i = this->size() - 2; i>=0; i--){
        if(newmax->oppervlakte() < operator[](i)->oppervlakte()){
            operator[](i).swap( newmax );
        }
    }

    this->resize(size() - 1);
    return max;
}
int main(){
    Blokkendoos blokkendoos("figuren.txt");
    cout<<endl<<"ALLE FIGUREN: ";
    cout<<blokkendoos<<endl;
    cout<<endl<<"DE 3 GROOTSTE, van groot naar klein: "<<endl;
    for(int i=0; i<3; i++){
        cout<<"figuur met grootste opp: "<<*blokkendoos.geef_figuur_met_grootste_oppervlakte()<<endl;
    }
    cout<<endl<<"DE NIEUWE BLOKKENDOOS BEVAT DEZE 3 NIET MEER: ";
    cout<<blokkendoos<<endl;
    return 0;
}