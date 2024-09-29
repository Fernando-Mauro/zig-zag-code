#include <bits/stdc++.h> 

using namespace std;
const int MAX =  (5 * 10000);

int convites[20002] = {0};

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    
    while(n--){
        int inicio, fin;
        
        cin >> inicio >> fin;
        convites[inicio + MAX]++;
        convites[fin + MAX]--;
    }

    

    return 0;
}
