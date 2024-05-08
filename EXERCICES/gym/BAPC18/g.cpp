#include <bits/stdc++.h>
using namespace std;

int n; string s;
vector<int> oi = {'A', 'B', 'C'};

int solve(){
    map<char,int> quant;
    map<char,int> ans;
    


    for(int i = 0; i < n; i++){
        quant[s[i]]++;
    }

    for(int i = 0; i < quant[oi[0]]; i++){
        if(s[i] != oi[0]) ans[oi[0]]++;
    }
    for(int i = quant[oi[0]]; i < quant[oi[0]] + quant[oi[1]]; i++){
        if(s[i] != oi[1])ans[oi[1]]++;
    }
    for(int i = quant[oi[0]] + quant[oi[1]]; i <quant[oi[0]] + quant[oi[1]] +  quant[oi[2]]; i++){
        if(s[i] != oi[2]) ans[oi[2]]++;
    }

    // cout << "2" << endl;


    int resp = ans[oi[0]] + ans[oi[1]] + ans[oi[2]];

    for(int l = 1; l <= n; l++){
        // cout << resp << endl;
        int r = l + n;
        int la = l;
        int ra = la + quant[oi[0]] - 1;
        int lb = ra + 1;
        int rb = lb + quant[oi[1]] - 1;
        int lc = rb + 1;
        int rc = lc + quant[oi[2]] - 1;
        if(s[la-1] == oi[0]) ans[oi[0]]++;
        if(s[ra] == oi[0]) ans[oi[0]]--;
        if(s[lb-1] == oi[1]) ans[oi[1]]++;
        if(s[rb] == oi[1]) ans[oi[1]]--;
        if(s[lc-1] == oi[2]) ans[oi[2]]++;
        if(s[rc] == oi[2]) ans[oi[2]]--;
        resp = min(resp, ans[oi[0]] + ans[oi[1]] + ans[oi[2]]);
        
    }

    return resp;
}



int main(){
    cin >> n;
    cin >> s;
    s.append(s);

    int resp = 1e9;

    do{
        resp = min(solve(), resp);
    }while(next_permutation(oi.begin(), oi.end()));


    cout << resp << endl;

}