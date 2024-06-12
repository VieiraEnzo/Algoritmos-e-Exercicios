#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

bool compare(string &a, string &b){
    return (a + b) < (b + a);
}

int main(){
    fastio;
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i< n; i++) cin >> v[i];
    
    sort(v.begin(), v.end(), compare);

    for(auto a : v){
        cout << a;
    }
}