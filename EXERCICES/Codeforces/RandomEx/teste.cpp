#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif


#define endl "\n"
#define int long long
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;




signed main(){
    fastio;
    int n, m, k; cin >> n >> m >> k;

    set<pair<int,pii>> entradas;
    vector<vector<pii>> saidas(n+1);
    for(int i = 0; i < m; i++){
        int d, f, t, c;
        cin >> d >> f >> t >> c;
        if(f == 0){ //saindo de 0
            saidas[t].push_back({c,d});
        }else{
            entradas.insert({d,{c,t}});
        }
    }

    for(int i = 0; i < n; i++){
        sort(saidas[i].rbegin(),saidas[i].rend());
    }

    int sol = 0;
    int MaxDias = 0;
    int qts = 0;
    vector<int> marc(n+1);
    for(auto a : entradas){
        int d = a.first;
        int c = a.second.first;
        int t = a.second.second;
        if(!marc[t]){
            entradas.erase(a);
            marc[t] = 1;
            sol += c;
            MaxDias = max(MaxDias, d);
            qts++;
        }
    }

    if(qts != n){
        cout << -1 << "\n";
        return 0;
    }
    
}