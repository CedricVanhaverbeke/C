#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v1;
    cout << "v1:" << endl;
    cout << "size: " << v1.size() << endl
         << "capaciteit: " << v1.capacity() << endl;
    //v1[0] = 4;
    //v1.at(0) = 6;
    v1.push_back(7);
    cout << "size: " << v1.size() << endl
         << "capaciteit: " << v1.capacity() << endl;
    v1[0] = 5;
    v1.push_back(6);
    v1.back() *= 2;
	cout << "size: " << v1.size() << endl
         << "capaciteit: " << v1.capacity() << endl;
    for (int i = 0 ; i < v1.size() ; i++)
       cout << v1[i] << "  ";
    cout << endl;
           
    vector<double> v2(4, 99.99);
    cout << "v2:" << endl;
    cout << "size: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl;
    for (int i : v2)
       cout << i << "  "; 
    cout << endl;
    v2.push_back(3.5);
    cout << "size: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl; 
    v2.push_back(6.2);
    cout << "size: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl;
    cout << "front: " << v2.front() << endl;
    cout << "back: " << v2.back() << endl;
    for (int i = 0 ; i < v2.size() ; i++)
       cout << v2.at(i) << "  "; 
    cout << endl;  
    v2.clear();
    cout << "size: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl;
    for (int i = 0 ; i < v2.capacity() ; i++)
       cout << v2[i] << "  ";  //crash bij v2.at(i)
    cout << endl;
    
    vector<char> v3;
    v3.reserve(5);
    cout << "v3:" << endl;
    cout << "size: " << v3.size() << endl
         << "capaciteit: " << v3.capacity() << endl;
    v3[0] = 'a';
    cout << "size: " << v3.size() << endl
         << "capaciteit: " << v3.capacity() << endl;
    v3.push_back('b');
    cout << "size: " << v3.size() << endl
         << "capaciteit: " << v3.capacity() << endl;
    for (char i : v3)
       cout << i << endl; 

    vector<string> tab[3];
    tab[0].push_back("een");
    tab[2].push_back("twee");
    tab[0].push_back("drie");
    for (int i = 0 ; i < 3 ; i++) {
        cout << "tabel " << i << ": ";
        for (int j = 0 ;  j < tab[i].size() ; j++)
           cout << tab[i][j] << " ";
        cout << endl;
    }
    return 0;
}
