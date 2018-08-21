#include <iostream>
#include <vector>

using namespace std;

typedef struct Persoon Persoon;
struct Persoon {
    string naam;
    int leeftijd;
};

ostream& operator<<(ostream& out, const Persoon & p){
    out<<p.naam<<" ("<<p.leeftijd<<" j)";
    return out;
}

template <class T>
void schrijf(vector<T> & v){
    cout << "[ " << v[0] << " |";
    for(int i = 1; i<v.size() -1; i++){
        cout << " " << v[i] << " |";
    }
    cout << " " << v[v.size()-1];
    cout << " ]" << endl;
}

int main(void){ 
    vector<int> v = {1, 2, 3};
    vector <bool> f = {false, true, false, true};
    vector<double> d = {0.5, 0.9, 0.13};
    vector <Persoon> p = { {"Cedric", 22} };
    schrijf(v);
    schrijf(f);
    schrijf(d);
    schrijf(p);

    return 0;
}