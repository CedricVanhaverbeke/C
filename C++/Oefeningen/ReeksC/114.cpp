#include "containers.h"
#define AANTAL 5

using namespace std;

void oef1(){
    stack<string> s;
    s.push("een");
    s.push("twee");
    s.push("drie");
    cout << s;
    cout << s;
}

void oef2(){
    vector<string> tabel[AANTAL];
    tabel[1] = {"aap", "noot", "mies"};
    for(int i = 0; i < AANTAL; i++){
        cout << tabel[i];
    }
}

void oef3(){
    vector<vector<int>> v;
    for(int i = 0; i<AANTAL; i++){
        vector<int> w;
        for(int j= 0; j<v.size(); j++){
            w[j] = 10 + 10*j;
        }
        v.push_back(w);
    }
}

int main(void){
    oef1();
    oef2();
    return 0;
}