#include <bits/stdc++.h>

using namespace std;

int main(){
    float x;
    cin >> x;
    float resultado = ((x + pow(x,2)) / ((5 * x) + 3));
    float y = (resultado + x) * (resultado / (resultado + (2 * x)));
    cout << y;
    return 0;
}