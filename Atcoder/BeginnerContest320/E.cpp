#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    ll n,m; cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll i =1; i <= n; i++) pq.push(i);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> back;
    vector<ll> comeu(n+1);
    fill(comeu.begin(), comeu.end(), 0);

    while (m--)
    {
        ll t, w, s; cin >> t >> w >> s;
        while(!back.empty() && back.top().first <= t)
        {
            pq.push(back.top().second);
            back.pop();
        }
        if(pq.empty()) continue;
        comeu[pq.top()] += w;
        back.push(make_pair(t+s,pq.top()));
        pq.pop();

    }
    
    for(ll i =1; i <= n; i++)
    {
        cout << comeu[i] << endl;
    }
    

}