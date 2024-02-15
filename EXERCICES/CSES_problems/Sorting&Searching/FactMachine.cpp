#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    ll n,t; cin >> n >> t;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>
    ,greater<pair<ll,ll>>> fila;

    vector<ll> v(n);

    for(ll i = 0; i < n; i++){
        ll a; cin >> a;
        fila.push({a,a});
        v[i] = a;
    }

    if(n == 1) {cout << t * v[0];return 1;}

    //reduce
    ll mdc = v[0];
    for(int i = 1; i < n; i++)mdc = __gcd(mdc,v[i]);

    ll mmc= 1;
    for(int i = 0; i< n; i++){
        mmc *= v[i];
    }mmc /= mdc; //mmc é o tempo

    ll Nprod = 0;
    for(int i = 0; i < n;i++){
        Nprod += mmc/v[i];
    }

    ll Rodadas = t/Nprod;

    t = t % Nprod;

    ll time = 0;
    while (t != 0)
    {
        ll tm = fila.top().first;
        ll mac = fila.top().second;
        fila.pop();
        t--;
        time = max(time, tm);
        tm += mac;
        fila.push({tm, mac});
            
    }

    cout << mmc * Rodadas + time << endl;
    
    
}
