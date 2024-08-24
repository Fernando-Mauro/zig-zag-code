#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        long long int N;
        cin >> N;
        vector<int> A = {1, 3, 6, 10, 15};
        int div = 1;
        for(int i = 0; i < 5; i++){
            if(N % A[i] == 0){
                div = A[i];
            }
        }
        int coins = N / div;
        int rem = N % div;
        for(int i = 4; i >= 0; i--){
            while(rem >= A[i]){
                coins += 1;
                rem -= A[i];
            }
        }
        cout << coins << "=\n";
     }
    return 0;
}