#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double x, y, z;
    cin >> x >> y >> z;

    double resultado = (x + (x*(y + pow(z, 2))))/((x + 3.141592) * (y + 3.141592));

    cout << setprecision(6) << resultado;
    return 0;
}