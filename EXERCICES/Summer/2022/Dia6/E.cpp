#include <bits/stdc++.h>
using namespace std;


int main(){
    int start = 1;
    int n, c, s; cin >> n >> c >> s;
    int ans = 0;

    if(s == 1) ans++;
    for(int i = 0; i < c; i++){
        int mov; cin >> mov;

        if(mov == 1){
            start = (start + 1)%(n+1);
            if(start == 0)start = 1;
        }else{
            start = (start - 1)%(n+1);
            if(start == 0)start = n;
        }

        if(start == s) ans++;
    }
    
    cout << ans << endl;
}