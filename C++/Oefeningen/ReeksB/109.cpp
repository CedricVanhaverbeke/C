#include <iostream>
#include <string>

using namespace std;

void vul_array(int * a, int * b , int * c, int grootte, function<int (int x, int y)> func){
    for(int i = 0; i<grootte; i++){
        c[i] = func(a[i], b[i]);
    }
}

void schrijf(string s, int * a, int grootte){
    for(int i = 0; i<grootte; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    const int GROOTTE = 10;
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int b[] = {0,10,20,30,40,50,60,70,80,90};
    int c[GROOTTE];

    vul_array(a,b,c,GROOTTE,[](int x, int y)->int{
        return x + y;
    });

    schrijf("SOM: ",c,GROOTTE);
    vul_array(a,b,c,GROOTTE, [](int x, int y)->int{
        return x * y;
    });
    schrijf("PRODUCT: ",c,GROOTTE);
    vul_array(a,b,c,GROOTTE,[](int x, int y)->int{
        return x - y;
    });
    schrijf("VERSCHIL: ",c, GROOTTE);
    return 0;
}