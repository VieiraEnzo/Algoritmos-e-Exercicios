#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    string s, t; cin >> s >> t;

    int t1 = s.size()-1;
    int t2 = t.size()-1;

    int it = 0;
    while (t1 - it >= 0 && t2 - it >= 0)
    {
        if(s[t1-it] == t[t2-it]) it++;
        else break;
    }
    
    cout << (t1-it+1) + (t2-it+1) << "\n";


}