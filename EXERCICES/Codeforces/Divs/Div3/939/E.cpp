#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;


bool f(int mid, string s){
    
    int it = 1;
    vector<int> freq(2*s.size(),1);
    int i = 0;
    for(i = 0; i + mid - 1 < s.size(); i++){
        it *= freq[i];
        if(it == 1){
            if(s[i] == '0'){
                it*= -1;
                freq[i + mid] *= -1;
                s[i] = '1';
            }
        }else{
            if(s[i] == '1'){
                it *= -1;
                freq[i+mid] *= -1;
                s[i] = '1';
            }else{
                s[i] = '1';
            }
        }
    }

    for(; i < s.size(); i++){
        it *= freq[i];
        if(it == -1){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }

    // cout << mid << " " << s << endl;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            return false;
        }
    }
    return true;
}


void solve(){
    
    int n; cin >> n;
    string s ;cin >> s;

    int l = 1; int r = s.size();

    int maxN = 1;
    for(int i = 2; i <= s.size(); i++){
        if(f(i, s)){
            maxN = max(i, maxN);
        }
    }
    
    cout << maxN << "\n";

}


int main(){
    
    fastio;

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

}