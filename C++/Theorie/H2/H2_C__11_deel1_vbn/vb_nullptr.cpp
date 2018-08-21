#include <iostream>
using namespace std;

void proc(int a) {
	cout << "procedure met parameter int\n";
}

void proc(char *a) {
	cout << "procedure met parameter char *\n";
}

int main() {
	proc(0);
	//onderstaande oproep geeft een error:
	//call of overloaded proc(NULL) is ambiguous
	//proc(NULL);
	proc(nullptr);
}

//wat gebeurt er als eerste proc in commentaar staat?
//en wat als de 2de proc in commentaar staat?
