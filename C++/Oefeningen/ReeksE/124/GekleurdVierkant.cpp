class GekleurdVierkant: public Vierkant, public GekleurdeRechthoek {
// geen extra attributen voorzien!
    public:
    GekleurdVierkant();
    GekleurdVierkant(int);
    GekleurdVierkant(int,string);
    void print();
};

GekleurdVierkant::GekleurdVierkant():GekleurdeRechthoek() {}
GekleurdVierkant::GekleurdVierkant(int zijde):GekleurdeRechthoek(zijde, zijde){ }
GekleurdVierkant::GekleurdVierkant(int zijde, string _kleur):GekleurdeRechthoek(zijde,zijde,_kleur) { }

void GekleurdVierkant::print(){
    Vierkant::print();
    cout << " kleur: " << kleur << endl;
}