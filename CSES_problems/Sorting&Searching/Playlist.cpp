#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n;cin >> n;
    vector<int> v(n);
    set<int> s;
    for(int i =0; i <n; i++)cin >> v[i];

    int ans =0, curr = 0;
    int index = 0;
    for(int i =0; i <n; i++){
        if(s.find(v[i]) == s.end())
        {
            s.insert(v[i]);
            curr++;

        }else{
            while (v[index] != v[i])
            {
                s.erase(v[index]);
                index++;
                curr--;
            }
            index++;           
        }
        ans = max(ans,curr);
    }
    cout << ans << endl;
}