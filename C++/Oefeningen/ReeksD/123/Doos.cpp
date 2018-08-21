
template <class T>
class Doos{
    private:
    vector<T> b;
    Doos<T> * c;
    Schijf<T> ** d;


    public:
    Doos();
    ~Doos();
    Doos(const Doos<T> & d);
    Doos(vector<T> b);
    Doos(Doos<T> * c);
    Doos(Schijf<T> ** d);
    Doos<T>& operator=(const Doos<T> & doos);
};

//Default constructor
template <class T>
Doos::Doos():b(4),c(0){
    d = new Schijf<T>*[3];
    for(int i = 0; i< 3; i++){
        d[i] = 0;
    }
}

//Destructor
Doos::~Doos(){
//Een vector zal automatisch verwijderd worden.
    (for int i = 0; i<3; i++){
        delete d[i];
    }
    delete []d;
    delete c;
}

//Copyconstructor
template <class T>
Doos::Doos(const Doos & d){
    b = doos.b;
    if(d.c != 0){
        c = new Doos<T>(*(d.c));
    }
    for(int i = 0; i<3; i++){
        if(d.d[i] != 0){
            d[i] = new Schijf<T>(*d.d[i]);
        } else {
            d[i] = 0;
        }
    }
}

template <class T>
Doos<T> & Doos<T>::operator=(const Doos & doos){
    if(this != &doos){ //Testen op adressen want voor de waarde zouden we een == moeten schrijven
        b = doos.b;
        delete c;
        if(doos.c!=0){
            c = new Doos<T>((*doos.c));
        }
        for(int i = 0; i<3;i++){
            delete d[i];   
        }
        // Want sowieso is de d van onze Doos al gevuld met 3 pointers.
        for(int i = 0; i<3;i++){
            if(doos.d[i] = 0){
                d[i] = 0;
            } else {
                d[i] = new Schijf<T>((*doos.d[i]))
            }
        }
    }
    return *this;
}

template <class T>
Doos::Doos(vector<T> & _b):Doos(), b(_b){

}

template <class T>
Doos::Doos(Doos<T> * c):Doos(){
    c = new Doos<T>(*c);
}

template <class T>
Doos::Doos(Schijf<T>** s):d(_d){
    b.resize(4);
    c = 0;
}