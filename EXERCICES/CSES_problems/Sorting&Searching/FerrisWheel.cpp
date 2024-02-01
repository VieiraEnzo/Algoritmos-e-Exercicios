#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, x; cin >> n >> x;
    multiset<int> frw;
    for(int i =0; i <n; i++){
        int temp; cin >> temp;
        frw.insert(temp);
    }

    int ans = 0;
    while (!frw.empty())
    {
        ans++;
        auto it = frw.begin();
        auto it2 = frw.upper_bound(x - *it);
        if(it2 == frw.begin()){frw.erase(frw.begin()); continue;}
        it2--;
        if(it2 == frw.begin()){frw.erase(frw.begin()); continue;}
        frw.erase(it);
        frw.erase(it2);
    }
    cout << ans << endl;

}