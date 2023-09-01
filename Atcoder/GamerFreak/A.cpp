#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)



int main(){
    fastio;
    int n,h,x;
    cin >> n >> h >> x;
    vector<int> v(n);
    for(int i =0; i < n; i ++){
        cin >> v[i];
    }
    int i =0;
    while (true)
    {   
        if(v[i] + h >= x){
            cout << i+1;
            return 0;
        }
        i++;
    }


}
