#include "Doos.cpp"

template <class T>
class Schijf{
    private:
    Doos<T> * doos;

    public:
    Schijf():a(0);
    ~Schijf();
    Schijf(const Schijf<T> & s);
    Schijf<T> & operator=(const Schijf<T> & s);
};

template <class T>
Schijf::~Schijf(){
    delete doos;
}

template <class T>
Schijf::Schijf(const Schijf & s){
    if(s.doos != 0){
        doos = new Doos<T>(*(s.doos))
    }
}

template <class T>
Schijf<T> & Schijf::operator=(const Schijf & schijf){
    if(this != &schijf) {
    delete doos;
    if(schijf.doos != 0){
        doos = new Doos<T>(*(schijf.doos));
    } else {
        doos = 0;
    }
    }
    return *this;
}

