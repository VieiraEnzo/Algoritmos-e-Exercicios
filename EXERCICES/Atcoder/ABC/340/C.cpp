#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;


int main(){
    fastio;
    ll n; cin >> n;

    map<ll,ll> cnt;
    map<ll,ll> vis;
    priority_queue<ll> fila;
    fila.push(n);
    cnt[n]++;
    vis[n] = 1;
    vis[1] = 1;

    ll ans = 0;
    while (!fila.empty())
    {
        ll a = fila.top();
        fila.pop();
        ans += cnt[a] * a;
        cnt[a/2]+= cnt[a];
        cnt[(a+1)/2]+= cnt[a];
        if(!vis[a/2]){
            vis[a/2]++;
            fila.push(a/2);
        }
        if(!vis[(a+1)/2]){
            vis[(a+1)/2]++;
            fila.push((a+1)/2);
        }

    }
    
    cout << ans << endl;

    

}