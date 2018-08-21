#include <string>
#include <iostream>

using namespace std;

string omgekeerde(std::string s){
    string output;
    for(int i = s.size(); i>=0 ;i--){
        output += s[i];
    }
    return output;
}

int main(){
    string s = omgekeerde("Hallo");
    cout << s;
}