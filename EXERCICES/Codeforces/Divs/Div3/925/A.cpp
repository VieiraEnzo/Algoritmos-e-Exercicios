#include <bits/stdc++.h>
using namespace std;

string search(int n){
    for(int i = 1; i <= 26; i++){
        for(int j = 1; j <= 26; j++){
            for(int k = 1; k <= 26; k++){
                if(i + j + k != n) continue;
                string s;
                s = s + (char)('a' + (i-1)) + (char)('a' + (j-1)) + (char)('a' + (k-1));
                return s;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    cout << search(n) << "\n";

}

int main(){
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}