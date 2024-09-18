#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int pan, jamon, queso, answer = 0, c = 0;
        cin >> pan >> queso >> jamon;
        while(true){
            if(c == 0 || c == 2){
                if(pan)pan--;
                else {break;}
                ++c;            }
            else if(c == 1 || c == 3){
                if(queso && pan){queso--;}
                else if(jamon && pan){jamon--;}
                else break;
                ++c;
            }
            else if(c == 4){
                if(pan)pan--;
                else {break;}
                c = 1;
            }
            ++answer;

        }
        cout << answer << "\n";
    }

    return 0;
}