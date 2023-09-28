#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n);
    vector<int> ls;
    for(int i =0; i <n; i++) cin >> v[i];

    for(int i =0; i <n; i++)
    {
        auto it = lower_bound(ls.begin(), ls.end(), v[i]); 
        if(it != ls.end())
        {
            *it = v[i];
        }
        else ls.push_back(v[i]);
    }

    cout << ls.size() << endl;

}