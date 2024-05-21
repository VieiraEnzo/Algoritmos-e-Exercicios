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
    int n; cin >> n;

    vector<int> pow;
    for(int i = 0; i < 31; i++){
        pow.push_back(1<<i);
    }

    multiset<int> s;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        s.insert(temp);
    }

    int last = -1;
    int ans = 0;
    bool found = false;
    for(auto num : s){
        if(num == last){if(!found) ans++; continue;}
        found = false;
        last = num;
        for(auto p : pow){
            auto a = s.find(p - num);
            if(a == s.end()) continue;
            if(*a == num && s.count(num) == 1) continue;
            found = true; break;
        }
        if(!found) ans++;
    }

    cout << ans << "\n";

}