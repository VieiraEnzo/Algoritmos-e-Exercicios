#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i64 = long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;string s;
    cin >> n >> s;
    const int mod = 1e9 + 7;
    set <vector<int>> set;
    for(int i = 0; i < (1<<n); i++){
        int one = 0, zero = 0;
        deque <int> d;
        for(int j = 0; j < n; j++){
            d.push_back(s[j]-'0');
        }
        int l = 1, r = n;
        vector <int> op;
        bool ok = true;
        for(int j = 0; j < n; j++){
            int v;
            if(i&(1<<j)){//est
                v = d.front();
                d.pop_front();
                op.push_back(l);
                l += 1;
            }else{
                v = d.back();
                d.pop_back();
                op.push_back(r);
                r -= 1;
            }
            if(v == 0){
                zero += 1;
                if(zero > one){
                    ok = false;
                }
            }else{
                one += 1;
            }
        }
        if(ok)
        set.insert(op);
    }
    cout << set.size()+1 << "\n";
    return 0;
}