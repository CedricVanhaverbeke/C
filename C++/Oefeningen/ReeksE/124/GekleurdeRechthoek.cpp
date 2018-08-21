
class GekleurdeRechthoek: public Rechthoek {
    public:
    GekleurdeRechthoek();
    GekleurdeRechthoek(int,int);
    GekleurdeRechthoek(int,int,string);

    void print() const;
    protected:
    string kleur;

};

GekleurdeRechthoek::GekleurdeRechthoek():Rechthoek(), kleur("onbekend"){ }
GekleurdeRechthoek::GekleurdeRechthoek(int _breedte, int _hoogte): Rechthoek(_hoogte, _breedte), kleur("onbekend") { }
GekleurdeRechthoek::GekleurdeRechthoek(int _breedte, int _hoogte, string _kleur): Rechthoek(_hoogte, _breedte), kleur(_kleur) { }

void GekleurdeRechthoek::print() const{
    Rechthoek::print();
    cout << " kleur: " << kleur << endl;
}