#include <string>
#include <iostream>
#include <functional>
using namespace std;

void overloop(const int t[], int n,
              function<void (int)> f) {
	for (int i=0; i<n; i++)
	   f(t[i]);
}

int main() {
    int divisor = 3;
    int numbers[] = { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
    
    //onderstaande lukt niet!
    //compileerfout: divisor is not captured
    /*
    overloop(numbers,12, [] (int y) {
        if (y % divisor == 0)
            cout << y << endl;
    });
    */
    
    cout << "volgende getallen uit numbers zijn door "
	    << divisor << ": ";
    overloop(numbers,12, [divisor] (int y) {
    	//volgende opdracht geeft compileerfout
    	//assignment of read-only variable divisor
    	//divisor = 3;
        if (y % divisor == 0)
            cout << y << " ";
    });
    
    cout << "\nvolgende getallen uit numbers zijn even: ";
    divisor = 2;
    overloop(numbers,12, [=] (int y) {
        if (y % divisor == 0)
            cout << y << " ";
    });
    
    cout << "\nsom van de even getallen is: ";
    int sum = 0;
    overloop(numbers,12, [divisor, &sum] (int y) {
        if (y % divisor == 0) {
           sum += y;
        }
    });   
	cout << sum << endl;
	//analoog aan [divisor, &sum] is
	//[&, divisor] en [=, &sum]
}



