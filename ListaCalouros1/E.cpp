#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;



int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<= n; i++)cin >> v[i];
    int sorted =0;
    for(int i=1; i<=n;i++){
        if(i == v[i]) sorted++;
    }
    int perct_trades =0;;
    for(int i=1; i<n; i++){
        for(int j =i+1; j <=n; j++){
            if(i == v[j] && j == v[i]){
                perct_trades++;
            }
        }
    }
    int k =0;
    int l =1, r =1;
    int not_sorted_or_perfect = n -sorted - 2*(perct_trades);
    if(!not_sorted_or_perfect){
        cout << perct_trades;
    }
    else{
        cout << (perct_trades) + (not_sorted_or_perfect -k);
    }
    

}
