#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> resp(n);

    int low = 1;
    int heigh = n;

    for(int i = 0; i < k; i++){
        int ind = 0;
        if(i%2 == 0){
            while (i + ind < n)
            {
                resp[i + ind] = heigh;
                heigh--;
                ind += k;
            }
        }else{
            while (i + ind < n)
            {
                resp[i + ind] = low;
                low++;
                ind += k;
            }
        }
    }

    for(auto a : resp){
        cout << a << " ";
    }  cout << endl;
}

int main(){
    fastio;
    int t; cin>> t;
    while (t--)
    {
        solve();
    }
    

    

}