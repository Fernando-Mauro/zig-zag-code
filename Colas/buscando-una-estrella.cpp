#include <iostream>
#include <queue>

using namespace std;

typedef long long int ll;

int main() {
  int n;
  cin >> n;
  priority_queue<ll> pq;
  for(int i=0; i<n; i++){
    char action;
    ll a;
    cin >> action;
    if(action == 'R'){cin >> a; pq.push(a*-1);}
    if(action == 'S'){if(pq.size() < 3)cout << "NO HAY SUFICIENTES PUNTAJES\n";
      else{
        long long int g, c, d;
        g = pq.top()*-1;
        pq.pop();
        c = pq.top()*-1;
        pq.pop();
        d =  pq.top()*-1;
        pq.pop();
        cout << g << " " << c << " " << d << endl;
        pq.push(g*-1);
        pq.push(c*-1);
        pq.push(d*-1);
      }
    }
    if(action == 'B')if(!pq.empty())pq.pop();
  }
  ll maxi = -1;
  if(!pq.empty()){
    while(!pq.empty()) {
        pq.pop();
    }
    maxi = pq.top()*-1;
    cout << "EL PUNTAJE MAS ALTO FUE " << maxi << endl; 
  }else cout << "NO HUBO GANADOR" << endl;
  
  return 0;
}