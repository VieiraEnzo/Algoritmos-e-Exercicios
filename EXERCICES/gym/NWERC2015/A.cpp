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
    ll livres = 0, reservados = 0;
    while (!v.empty())
    {
        auto a = v.top();
        v.pop();
        cout << a.first << " " << a.second << endl;

        if(a.second == 0){
            livres++;
            v.push({a.first + m, 2});
        }else if(a.second == 1){
            if(livres > 0){
                livres--;
            }else{
                criados++;
            }
            //não esquecer de apagar o evento de saida
        }else if(a.second == 2){
            livres--;
        }

    }
    

    cout << criados << endl;


}