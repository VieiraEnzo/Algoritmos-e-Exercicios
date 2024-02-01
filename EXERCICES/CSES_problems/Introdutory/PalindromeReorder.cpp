#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    map<char,int> pa;
    string s; cin >> s;
    for(int i =0; i < s.size(); i++) pa[s[i]]++;
    vector<char> resp;
    
    auto it = pa.begin();
    while (it != pa.end())
    {
        while ((*it).second > 1)
        {
            pa[(*it).first] -= 2;
            resp.push_back((*it).first);
        }
        it++;
        
    }

    bool first = false;
    for(auto a : pa){
        if(pa[a.first] == 1) 
            if(!first){
                first = true;
            }
            else{
                cout <<  "NO SOLUTION"; return 0;
            }
        }


    for(auto a : resp) cout << a;
    for(auto a : pa){if(pa[a.first] == 1) cout << a.first;}
    for(int i =resp.size()-1; i >= 0; i --) cout << resp[i];


}