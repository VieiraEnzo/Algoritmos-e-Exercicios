#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
            vector<int> v(n + 1);
            vector<queue<int>> res(n+1);
            for(int i = 0; i < n; i++) cin >> v[i];

            string ans;
            char letter = 'a';
            for(int i = 0; i < n; i++){
                if(res[v[i]].empty()){
                    ans.push_back(letter);
                    res[v[i]+1].push(letter);
                    letter++;
                }else{
                    ans.push_back(res[v[i]].front());
                    res[v[i]+1].push(res[v[i]].front());
                    res[v[i]].pop();
                }
            }

            cout << ans << endl;
    }
    
    

}