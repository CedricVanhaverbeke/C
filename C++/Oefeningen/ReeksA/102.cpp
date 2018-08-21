#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
    cout << setw(8) << "DEC" << setw(8) << "OCT" << setw(8) << "HEX" << endl;
    cout << "--------------------------" << endl;
    for(int i = 0; i<=64; i++){
        cout << setw(8) << dec << i << setw(8) << oct << i << setw(8) << hex << i << endl;
    }
    return 0;
}