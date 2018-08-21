#include "Rechthoek.cpp"
#include "GekleurdeRechthoek.cpp"
#include "Vierkant.cpp"
#include "GekleurdVierkant.cpp"
#include <vector>

// Als je wil bereiken wat ze u vragen gebruik je pointers.
// In de basisklasse maak je de printmethode van rechthoek ook virtual en tada
// Je kan het met gewone pointers doen of unique_ptr.
// Ik heb ze hier allebei uitgeschreven

void pointers(){
    Rechthoek  r2(4,6);
    GekleurdeRechthoek  gr1;
    GekleurdeRechthoek  gr3(6,9,"rood");
    Vierkant v2(10);
    vector<Rechthoek*> v;

    // Let op de moves hier: Super belangrijk. Zo worden nergens kopieën genomen
    v.push_back(move(&r2));
    v.push_back(move(&gr1));
    v.push_back(move(&gr3));
    v.push_back(move(&v2));
    for(auto x : v){
    (*x).print();
    cout << " oppervlakte: " << (*x).oppervlakte() << endl
    << " omtrek: " << (*x).omtrek() << endl;
    }
}

void uniquepointers(){
    Rechthoek  r2(4,6);
    GekleurdeRechthoek  gr1;
    GekleurdeRechthoek  gr3(6,9,"rood");
    Vierkant v2(10);
    vector<unique_ptr<Rechthoek>> v;
    v.push_back(unique_ptr<Rechthoek>(move(&r2)));
    v.push_back(unique_ptr<Rechthoek>(move(&gr1)));
    v.push_back(unique_ptr<Rechthoek>(move(&gr3)));
    v.push_back(unique_ptr<Rechthoek>(move(&v2)));

    // Blijkbaar als je een vector van unique_ptr overloopt: & x!
    for(auto & x : v){
    (*x).print();
    cout << " oppervlakte: " << (*x).oppervlakte() << endl
    << " omtrek: " << (*x).omtrek() << endl;
    }
    // Dit moet omdat we dynamisch een vector opvullen in deze methode, anders neut C++
    for(auto & x : v){
        x.release();
    }
}

int main () {
    pointers();
    uniquepointers();
    return 0;
}