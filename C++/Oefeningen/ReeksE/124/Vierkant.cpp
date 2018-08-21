
class Vierkant: public Rechthoek {
    public:
    Vierkant();
    Vierkant(int);
    void print() const;
    
};

Vierkant::Vierkant():Rechthoek() { }
Vierkant::Vierkant(int zijde):Rechthoek(zijde, zijde) { }

void Vierkant::print() const{
    cout << "Vierkant: zijde " << hoogte << endl;
}