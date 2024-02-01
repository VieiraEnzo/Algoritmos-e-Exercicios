#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 2000005

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, q; cin >> n >> q;


    // Calcular os crivos
    vector<bool> is_prime(MAXN+1, true);
    vector<int> mdiv(MAXN);
    for(int i = 0; i < MAXN; i++)mdiv[i] = i;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i] && (long long)i * i <= MAXN) {
            for (int j = i; j <= MAXN; j += i){
                is_prime[j] = false;
                mdiv[j] = i;
            }
        }
    }

    
    priority_queue<pair<int,int>> mult;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        if(temp == 1) ans[i] = 0;
        else mult.push({temp,-i});
    }

    int rodada = 1;
    while (mult.size())
    {
        auto temp = mult.top();
        mult.pop();
        auto num = temp.first;
        auto pos = temp.second;
        if(mdiv[num] == num){
            ans[-pos] = rodada;
        }
        else mult.push({num/mdiv[num], pos});
        rodada++;
    }


    //sparce table para saber maximo em um intervalo
    int lg[n + 1];
    lg[1] = 0;
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;


    int K = 26;
    int st[K][n];

    copy(ans.begin(), ans.end(), st[0]);

    for(int i = 1; i <= K; i++)
        for(int j = 0; j + (1<<i) <= n; j++)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);


    while (q--)
    {
        int l ,r; cin >> l >> r;l--;r--;

        int  i = lg[r - l + 1];
        int maxi = max(st[i][l], st[i][r - (1<<i) + 1]);

        cout << maxi << endl;
    }
    


    
    
}