#include <bits/stdc++.h>
#pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

ll lis(vector<ll> &vec){
    multiset<ll> s;

    for(ll i = 0; i < vec.size(); i++){
       s.insert(vec[i]);

       auto it = s.upper_bound(vec[i]);

       if(it != s.end()) s.erase(it);
    }

    return s.size();
}


int main(){
    fastio;
    ll n; cin >> n;
    vector<char> Per{'E', 'R', 'S', 'W'};
    sort(Per.begin(), Per.end());
    vector<string> v(n);
    for(ll i = 0; i < n; i++)cin >> v[i];
    
    ll ans = 0;
    do
    {
        vector<ll> vec;
        ll indE, indR, indS, indW, indC = n*4;
        for(ll i = 0; i < 4; i++){
            if(Per[i] == 'E') indE = n*i;
            if(Per[i] == 'R') indR = n*i; 
            if(Per[i] == 'S') indS = n*i;
            if(Per[i] == 'W') indW = n*i;
        }

        for(ll i = 0; i < n; i++){
            if(v[i][0] == 'E') vec.push_back(indE + stoi(v[i].substr(1)));
            if(v[i][0] == 'R') vec.push_back(indR + stoi(v[i].substr(1))); 
            if(v[i][0] == 'S') vec.push_back(indS + stoi(v[i].substr(1)));
            if(v[i][0] == 'W') vec.push_back(indW + stoi(v[i].substr(1)));
            if(v[i][0] == 'C') vec.push_back(indC + stoi(v[i].substr(1)));
        }

        ans = max(ans, lis(vec));

    }while(next_permutation(Per.begin(), Per.end()));
    

    cout << n - ans << endl;
    

}