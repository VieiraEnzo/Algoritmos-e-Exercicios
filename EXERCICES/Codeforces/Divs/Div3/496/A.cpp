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
    int init;
    int ans = 1;
    cin >> init;
    vector<int> stairs;
    for(int i = 1; i < n; i++){
        int temp; cin >> temp;
        if(temp > init) {init = temp;continue;}
        stairs.push_back(init);
        init = temp;
        ans++;
    }
    stairs.push_back(init);

    cout << ans << "\n";
    for(auto a : stairs){
        cout << a << " "; 
    }cout << "\n";
}