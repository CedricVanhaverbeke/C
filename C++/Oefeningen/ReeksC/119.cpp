// De trick is hier om gebruik te maken van een set
#include "containers.h"


// Clue van de zaak: Als je elementen verwijdert in de lijst en earease(it) zou doen dan is de iterator zinloos geworden. Hij wijst naar iets anders en werkt dus niet goed meer.
// Oplossing daarvoor: een hulpiterator
// Probleem daarmee: Uw einde past zich de hele tijd aan. De oorspronkelijke it != end zal dus niet meer juist zijn. (Kijk maar eens naar de output van dit programma)
// Enige oplossing is zoals ze tonen in de oplossingen zelf: Per 3 omhoog gaan met i en wachten tot i groter is dan het oorspronkelijke aantal
// Ik dacht om de eindgrens voortdurend aan te passen maar blijkbaar is een set zo slim niet. DIT WERKT DUS NIET
int main(void){
    // Een set zal ze automatisch in alfabetische volgorde zetten als je ze afloopt met een iterator 
    set<string> woorden = {"appel", "zuurtegraad", "vleermuis", "lekker", "kookboek", "c++", "Croque Monsieur", "Manneke Pies", "yow"};
    int teller = 0;
    set<string>::iterator it = woorden.begin();
    set<string>::iterator end = woorden.end();
    while(it != end){
        if(teller%3 == 0){
            set<string>::iterator hulp = it;
            it++;
            cout << "Woord " << *hulp << " wordt verwijderd." << endl;
            woorden.erase(hulp);
        }
        cout << *it << endl;
        teller++;
        it++;
        end = woorden.end();
    }
    //cout << woorden;
    return 0;
}  