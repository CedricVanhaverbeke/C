#include <iostream>
#include <cstdlib>

#define AANTAL 5
#define LENGTE 3

using namespace std;

string genereer_string(int n){
    string output = "";
    for(int i = 0; i < n; i++){
        char c = (rand() % 26) + 'a';
        output += c;
    }
    return output;
}

void vul_array_met_strings(string * tab, int n, int len){
    for(int i =0; i<n; i++){
        tab[i] = genereer_string(len);
    }
}

void print_string(string * tabel, int lengte){
    for(int i = 0; i < lengte; i++){
        cout << tabel[i] << endl;
    }
}

/* De &'en zijn belangrijk. Anders wordt een kopie meegegeven. */
void bepaal_min_en_max(string * tabel, int n, string & min, string & max){
    min = tabel[0];
    max = tabel[0];
    for(int i = 1; i < n; i++){
        if(tabel[i] < min){
            min = tabel[i];
        }
        if(tabel[i] > max){
            max = tabel[i];
        }
    }
}

/* Belangrijk hier om de tabel te initialiseren met een aantal, anders is er geen geheugen vrij
   en kan er geen string in de tabel geduwd worden */
int main(void){
    srand(time(NULL));
    string tabel[AANTAL];
    vul_array_met_strings(tabel, AANTAL, LENGTE);
    print_string(tabel, AANTAL);

    string min = "";
    /* Nekeer een constructor getest */
    string max("");
    bepaal_min_en_max(tabel, AANTAL, min, max);
    cout << "Minimum: " << min << endl << "Maximum: " << max;
    return 0;
}