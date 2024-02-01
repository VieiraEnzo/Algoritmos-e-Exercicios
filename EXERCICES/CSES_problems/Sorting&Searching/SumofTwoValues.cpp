#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

bool compare(pair<int,int> a, int b){
    return a.first < b;
}

int main(){
    fastio;
    int n,x; cin >> n >> x;
    vector<pair<int,int>> v(n);
    for(int i =0; i <n; i++){
        int temp; cin >> temp;
        v[i] = make_pair(temp, i);
    }
    sort(v.begin(), v.end());
    for(int i =0; i < n; i++){
        auto it = lower_bound(v.begin(), v.end(), x-v[i].first, compare);
        pair<int,int> resp = *it;
        if(v[i].second == resp.second) it++;
        resp = *(it);
        if(resp.first == x-v[i].first && it != v.end()){
            cout << v[i].second + 1 << " " << resp.second + 1<< endl;
            return 0;
        }
    }


    cout << "IMPOSSIBLE" << endl;

    

}