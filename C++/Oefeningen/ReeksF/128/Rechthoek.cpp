#include <iostream>
using namespace std;

class Rechthoek {
    public:
    Rechthoek();
    Rechthoek(int, int);

    virtual void print() const;
    int oppervlakte() const;
    int omtrek() const;

    private:
    int breedte;

    // Hier maken we hoogte protected omdat we aan dit attribuut moeten kunnen in Vierkant. De printmethode moet daar anders
    protected:
    int hoogte;
};

Rechthoek::Rechthoek():hoogte(1),breedte(1){ }

Rechthoek::Rechthoek(int _breedte, int _hoogte): hoogte(_hoogte), breedte(_breedte){ }

int Rechthoek::oppervlakte() const{
    return hoogte * breedte;
}

int Rechthoek::omtrek() const{
    return (2*hoogte + 2*breedte);
}

void Rechthoek::print() const{
    cout << "Rechthoek: " << hoogte << " op " << breedte << endl;
}

