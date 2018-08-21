#include <iostream>
#include <vector>

using namespace std;
int main(void){
    int d;
    cin >> d;
    vector<int> v;
    while(d != -1){
        v.push_back(d);
        cin >> d; 
    }
    for(int i = 0; i<v.size(); i++){
        cout << v[i];
    }
}