#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int a, b, c,n;
    scanf("%d%d%d%d", &a, &b, &c, &n);
    if(a >= 1 && b >= 1 && c >= 1 && a + b + c >= n && n >= 3){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}