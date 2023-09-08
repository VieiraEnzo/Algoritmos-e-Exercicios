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
        vector<pair<int,int>> v(n);
        vector<bool> sala(400);
        fill(v.begin(),v.end(),make_pair(-1,-1));
        fill(sala.begin(),sala.end(), false);
        for(int i =0; i< n; i++){
            int d,s; cin >> d >> s;
            v[i] = make_pair(d,s);
        }
        for(auto a : v){
            int seg = a.second;
            if(seg %2){seg++;}
            sala[(a.first + (seg/2))] = true;
        }
        int resp;
        for(int i =0; i < 400; i ++){
            if(sala[i]){
                resp = i-1;
                break;
            }
        }
        cout << resp << endl;

    }
    

}