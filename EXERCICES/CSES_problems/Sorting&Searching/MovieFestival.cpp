#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<pair<int,int>> org(n);
    for(int i = 0; i <n; i++) cin >> org[i].second >> org[i].first;
    sort(org.begin(), org.end());
    
    int ans = 0, time_end_last = -1;
    for(int i =0; i <n; i++){
        if(org[i].second >= time_end_last){
            ans ++;
            time_end_last = org[i].first;
        }
    }
    cout << ans << endl;
    

}