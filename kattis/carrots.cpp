// https://open.kattis.com/problems/carrots
#include <bits/stdc++.h>
#define MAX_LIMIT 100
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, p;
    scanf("%d%d", &n, &p);
    char trash[MAX_LIMIT], ch;
    ch = getchar();
    const int aux = p;
    while(p--){
        scanf("%[^\n]%*c", trash);
    }
    printf("%d\n", aux);
    return 0;
}