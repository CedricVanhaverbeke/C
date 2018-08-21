#include <string>
#include <string>
#include <iostream>
using namespace std;

class Persoon {
	public:
		Persoon(const string &nm, int lft) : naam(nm), leeftijd(lft) {}
		void print() {
			cout << naam << " " << leeftijd << endl;
		}
	private:
		string naam;
		int leeftijd;
};

int main() {
	int a=2, b=3;
	a = move(b);
	cout << a << " " << b << endl;
	
	string s1 = "string1", s2 = "string2";
	s1 = move(s2);
	cout << s1 << " " << s2 << endl;
	
	Persoon p1("maya",12);
	Persoon p2(p1);
	p1.print();
	p2.print();
	Persoon p3(move(p1));
	p1.print();
	p3.print();
}




