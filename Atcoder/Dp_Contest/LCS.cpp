#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;



int main(){
    //fastio;
    string s, t;
    cin >> s >> t;
    int dp[s.size() + 1][t.size() + 1];

    for(int i = 0; i <= t.size(); i++)dp[s.size()][i] = 0;
    for(int i = 0; i <= s.size(); i++)dp[i][t.size()] = 0;


    for(int i = s.size()-1; i>=0; i--)
        for(int j = t.size()-1; j>=0; j--){
            if(s[i] == t[j])
                dp[i][j] = dp[i+1][j+1] + 1;
            else{
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }

    
    string ans = "";
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {   
        if(s[i] == t[j]){
            ans.push_back(s[i]);
            i += 1; j += 1;
            }
        else{
            if(dp[i][j+1] > dp[i+1][j]){
                j +=1;
            }else{
                i+=1;
            }

        }
    }

    cout << ans << endl;
    
}