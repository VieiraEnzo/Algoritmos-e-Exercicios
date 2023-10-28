#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, m,k; cin>>n>>m>>k;
    vector<int> desir(n);
    multiset<int> apt;
    for(int i =0; i < n; i ++)cin>> desir[i];
    for(int i =0; i < m; i ++){
        int temp; cin >> temp;
        apt.insert(temp);
    }
    sort(desir.begin(), desir.begin()+n);

    int index = 0;
    for(int i =0; i < n; i++){
        auto it  = apt.lower_bound(desir[i]-k);
        if(it == apt.end()) continue;
        else if(*it > desir[i] +k) continue;
        apt.erase(it);index++;
    }

    cout << index << endl;
}