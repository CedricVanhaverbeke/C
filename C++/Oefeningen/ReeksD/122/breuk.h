#include <iostream>
#include <fstream>
#include <string> // nodig bij het inlezen van een breuk
#include <sstream> // vergelijk met Scanner(String) in Java
#include <cmath> // abs berekent absolute waarde van een int (fabs is voor double)
#include <set>

using namespace std;

class Breuk {
    private:
    int teller,noemer;
    void normaliseer();

    public:
    Breuk(int t = 0, int n=1):teller(t),noemer(n){ normaliseer(); }
    //Enkel in de declaratie het keyword friend vermelden
    friend ostream & operator<<(ostream & out, const Breuk & b);
    friend istream & operator>>(istream & in, Breuk & b);
    friend string is_stambreuk(Breuk & b);
    friend Breuk operator+(int x, const Breuk & b);
    //Operatoren
    Breuk operator+(const Breuk & b) const;
    Breuk operator-() const;
    Breuk operator-(const Breuk & b) const;
    Breuk & operator+=(const Breuk & b);
    Breuk & operator-=(const Breuk & b);
    Breuk & operator++();
    Breuk operator++(int x);
    bool operator==(const Breuk & b) const;
    bool operator!=(const Breuk & b) const;
    bool operator<(const Breuk & b) const;

    Breuk operator+(int x) const;
};