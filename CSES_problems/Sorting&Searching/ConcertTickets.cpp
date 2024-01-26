3 4
...#
.#..
....
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n,m; cin >> n >> m;
    multiset<int> price;
    for(int i =0; i < n; i++){int temp; cin >> temp; price.insert(temp);}

    for(int i =0; i < m; i++){
        if(price.empty()){ cout << -1 << endl;continue;}
        int cust; cin >> cust;
        auto it = price.upper_bound(cust);
        if(it == price.begin()){ cout << -1 << endl;continue;}
        it--;
        cout << *it << endl;
        price.erase(it);
    }

}