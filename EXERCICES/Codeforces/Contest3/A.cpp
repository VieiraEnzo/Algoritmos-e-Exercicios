#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;
        vector<char> v(n);
        for(int i = 0; i< n; i++) cin >>v[i];

        int firstB = -1;
        int lastB = -1;
        for(int i = 0; i < n; i++){
            if(v[i] == 'B'){
                if(firstB == -1){
                    firstB = i;
                }
                lastB = i;
            }
        }       
        cout << lastB - firstB + 1 << endl;
    }
    
    
    

}