#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<int> s(n);
    for(int i=0; i <n; i++) cin >> s[i];
    vector<int>sub(n);
    int impar = 0;

    int ans = 0;
    int par_0 =0;
    int par_1 = 0;
    int impar_0 = 0;
    int impar_1 = 0;
    if(s[0]){impar++;impar_1++;sub[0]=1;}
    else{par_0++;sub[0]=0;}

    for(int i =1; i < n; i++){
        if(s[i]){
            impar = (impar+1)%2;
            if(impar){
                impar_1++;
                sub[i] = par_0 + impar_1;
            }
            else{
                par_1++;
                sub[i] = impar_0 + par_1;
            }
        }
        else{
            if(impar){
                impar_0++;
            }
            else{
                impar_1++;
            }
            sub[i] = sub[i-1];
        }
    }
    for(int i =0; i < n; i++){
        ans += sub[i];
    }
    cout << ans << endl;


}