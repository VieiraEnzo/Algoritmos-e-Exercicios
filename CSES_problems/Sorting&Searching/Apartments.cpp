#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, m,k; cin>>n>>m>>k;
    vector<int> desir(n);
    vector<int> apt(n);
    for(int i =0; i < n; i ++)cin>> desir[i];
    for(int i =0; i < m; i ++)cin>> apt[i];
    sort(desir.begin(), desir.begin()+n);
    sort(apt.begin(), apt.begin()+m);

    int index = 0;
    for(int i =0; i < n; i++){
        if(apt[index] >= desir[i]-k && apt[index] <= desir[i]+k){
            index++;
        }   
    }

    


}