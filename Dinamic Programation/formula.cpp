#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    float resultado = ((-1 *b) + sqrt(pow(b,2) - (4 * a * c))) / (2 * a);
    float segundo = ((-1 *b) + sqrt(pow(b,2) - (4 * a * c))) / (2 * a);
    cout << resultado << endl << segundo;
    return 0;
}