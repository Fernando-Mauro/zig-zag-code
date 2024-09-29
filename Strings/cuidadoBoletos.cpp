#include <bits/stdc++.h> 

using namespace std;


bool isSecure(string &password, vector <string> &commmonWords){
    
   

    return true;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;

    while(q--){
        int common;
        cin >> common;

        vector <string> commonWords(common);
        for(int i = 0; i < common; ++i){
            cin >> commonWords[i];
        }
        string password;
        cin >> password;

        if(isSecure(password, commonWords)){
            cout << "SI\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}