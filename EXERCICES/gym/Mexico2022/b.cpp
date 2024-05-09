#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxn = 1e5 + 7;
vector<vector<ll>> grafo(maxn);
vector<vector<ll>> marc(maxn, vector<ll> (101));
priority_queue<ll , vector<ll>, greater<ll> > pq;
vector<ll> inpq(maxn);
vector<ll> ans;

ll k;

void bfs(ll v){

    queue<pair<ll,ll>> fila;
    fila.push({v, 0});
    marc[v][0] = 1;

    while (!fila.empty())
    {
        auto p = fila.front();
        fila.pop();
        for(auto viz : grafo[p.first]){
            ll dist = p.second + 1;
            if(dist > k) return;
            if(!marc[viz][dist]){
                fila.push({viz, dist});
                marc[viz][dist] = 1;
                if(!inpq[viz]) {pq.push(viz);inpq[viz] = 1;}
            }
        }
    }
    

}

void search(ll n){

    while (ans.size() != n)
    {
        ll in = pq.top();
        pq.pop();
        ans.push_back(in);
        bfs(in);
    }
}

int main(){

    cin.tie(0), ios_base::sync_with_stdio(0);

    ll n; cin >> n >> k;   
    for(ll i = 0; i < n-1 ;i++)
    {   ll a, b; cin >> a >> b;
        grafo[a].push_back(b); 
        grafo[b].push_back(a);
    }

    pq.push(1);
    inpq[1] = 1;

    search(n);

    for(auto a : ans){
        cout << a << " ";
    }cout << "\n";

}