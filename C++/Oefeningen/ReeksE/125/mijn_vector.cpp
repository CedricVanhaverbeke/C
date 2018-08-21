#include <fstream> 
#include <iostream>

using namespace std;

template <class T>
//Belangrijk: Je mag geen <T> in de declaratie van je klasse schrijven. Spannend zeg
class mijn_vector: public vector<int>{
    //Een beetje vreemd dit: eerst de <T> daarachter het basistype
    using vector<int>::vector; 
    private:

    public:
    friend ostream & operator<<(ostream &, mijn_vector<T> &);
};

template <class T>
ostream & operator<<(ostream & out, mijn_vector<T> & v){
    for(int i = 0; i<v.size(); i++){
        out << v[i] << " ";
    }
    return out;
}