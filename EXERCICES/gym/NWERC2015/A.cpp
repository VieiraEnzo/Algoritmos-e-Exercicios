#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    ll n, m; cin >> n >> m;
    priority_queue<pll, vector<pll> , greater<pll>> v;

    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        v.push({a, 1});
        v.push({a+b, 0});
    }
    

    ll criados = 0;
    priority_queue<ll, vector<ll> , greater<ll>> livres;
    while (!v.empty())
    {
        auto a = v.top();
        v.pop();
        // cout << a.first << " " << a.second << endl;

        if(a.second == 0){
            livres.push(a.first+m);
            
        }else if(a.second == 1){
            
            while (!livres.empty() && livres.top() < a.first)
            {
                livres.pop();
            }
            if(livres.size() > 0){
                livres.pop();
            }else{
                criados++;
            }

            
            //não esquecer de apagar o evento de saida
        }

    }
    

    cout << n - criados << endl;


}