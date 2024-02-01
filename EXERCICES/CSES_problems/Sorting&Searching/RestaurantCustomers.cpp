#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<pair<ll,ll>> v;
    for(int i =0; i <n; i++){
        ll temp1,temp2; cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1,1));
        v.push_back(make_pair(temp2,0));
    }
    sort(v.begin(), v.end());
    int ans = 0,curr = 0;
    for(int i =0; i < 2*n; i++){
        if(v[i].second){
            curr++;
        }
        else{
            curr--;
        }
        ans = max(ans,curr);
    }
    cout << ans << endl;

}