#include<bits/stdc++.h>
using namespace std;


int main(){

    cin.tie(0), ios_base::sync_with_stdio(0);

    int n; cin >> n;

    while (n--)
    {
        int x; cin >> x;

        int ans = 0;
        for(int i = 1; i * i <= x; i++){
            if(x % i == 0){
                if(i*i == x) ans += 1;
                else ans += 2;
            }
        }

        cout << ans  << endl;
    }
    

}