#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int n_primo[10000000];


int main(){
    fastio;
    int t; cin >> t;
    fill(n_primo, n_primo + 10000000, 1);
    //crivo(10000000);
    vector<int> somas;
    // somas.push_back(n_primo[0]);
    // for(int i =1; i< 10000000; i++){
    //     somas.push_back(somas[i-1] + n_primo[i]);
    // }

    while (t--)
    {
        int l , r;
        cin >> l >> r;
        if(r == l){
            if(l%2){
                bool found = false;
                l -= 3;
                for(int i = 3; i < (l/2)+1; i++){
                    if(gcd(i,l) != 1){
                        cout << i << " " << l << endl;
                        found = true;
                        break;
                    }
                    l--;
                }
                if(!found)cout << -1 << endl;
            }
            else{
                cout << 2 << l-2 << endl;
            }
            
        }
        else{
            if(r%2)r--;
            if(gcd(2,r-2) != 1 && r-2 != 0){cout << 2 << " " << r-2 << endl;}
            else{cout << -1 << endl;}
        }

    }
    

}