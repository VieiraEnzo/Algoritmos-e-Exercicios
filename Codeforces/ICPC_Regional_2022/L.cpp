#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;



int main(){
    fastio;
    string s;int k; cin >> s >> k;
    vector<char> sub;
    for(int l =0; l < k; l++){ 
        sub.clear();
        for(int i =l; i < s.size();i +=k){
            sub.push_back(s[i]);
        }
        sort(sub.begin(),sub.end());
        int j = 0;
        for(int  i=l; i < s.size(); i+=k){
            s[i] = sub[j];
            j++;
        }
    }
    cout << s << endl;
}   