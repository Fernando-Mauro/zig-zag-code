// https://omegaup.com/arena/problem/Pilas-de-tarjetas/
#include <iostream>

using namespace std;

int mcd(int a, int b) {
    if (b == 0) return a;
    return mcd(b, a % b);
}
int main(){
   cout << mcd(450,840);
   return 0;
}