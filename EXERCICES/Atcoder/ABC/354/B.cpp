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
    vector<string> name(n);

    int T = 0;
    for(int i = 0; i < n ;i++){
        int temp;
        cin >> name[i] >> temp;
        T += temp;
    }   

    sort(all(name));

    cout << name[T%n] << "\n";

}