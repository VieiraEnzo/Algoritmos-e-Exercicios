#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
int resp = 0;

int find_perfect_trades(vector<int> &v, int n)
{   
    int trades = 0;
    for(int i=1; i<n; i++){
        for(int j =i+1; j <=n; j++){
            if(i == v[j] && j == v[i]){
                v[j] = j;
                v[i] = i;
                trades+=2;
                resp += 1;
            }
        }
    }
    return trades;
}

int last(int n, vector<int> &v)
{   
    int trades = 0;
    for(int i=1; i<n; i++){
                if(i != v[i]){
                    for(int j = i; j <= n; j++){
                        if(v[j] == i){
                            v[j] = v[i];
                            v[i] = i;
                            trades++;
                            resp+=1;
                            return trades;
                        }
                    }
                }
            }
    return trades;
}



int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<= n; i++)cin >> v[i];
    int sorted =0;
    int perct_trades =0;
    int trades = 0;

    for(int i=1; i<=n;i++)if(i == v[i]){trades++;}
    while (trades != n)
    {
        trades += find_perfect_trades(v,n);
        if(trades != n)
        {
            trades += last(n,v);
        }
    }
    cout << resp << endl;
    

}
