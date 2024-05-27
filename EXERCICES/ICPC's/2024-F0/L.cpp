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
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    int n; cin >> n;
    map<string , int> nomes;
    map<int, string> rnomes;
    vector<string> ordem(n);
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> ordem[i];
    }

    for(int i = 0; i < n; i++){
        string nome; cin >> nome;
        nomes[nome] = i;
        rnomes[i] = nome;
        s.insert(i);
    }

    for(int i = 0; i < n-1; i++){
        cout << rnomes[*s.begin()] << " ";
        s.erase(nomes[ordem[i]]);
    }
    cout << rnomes[*s.begin()] << "\n";

}   