#include <bits/stdc++.h>

using namespace std;

int solve(int &number){
    int count = 0; 
    int raiz = sqrt(number);
    for(int i = raiz; i >= 1 && number > 0; --i ){
        if(number - pow(i,2) >= 0){
            number -= pow(i,2);
            count++;
            i++;
        }

    }
    return count;
}
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    while(n--){
        int caso;
        scanf("%d", &caso);
        printf("%d\n",solve(caso));
    }
    return 0;
}