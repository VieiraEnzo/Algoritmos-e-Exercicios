#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int k, n;


bool consistent(int p1, int p2 ,vector<vector<int>> &v)
{
    for(int i= 0; i < k; i++)
    {
        int ipos, jpos;
        for(int j = 0; j < n; j++)
        {
            if(v[i][j] == p1)ipos = j;
            if(v[i][j] == p2)jpos = j;
        }
        if(jpos < ipos) return false;
    }
    return true;

}


int main()
{
    fastio;
    ifstream fin("gymnastics.in");
    fin >> k >> n;
    vector<vector<int>> v(k, vector<int>(n));
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            fin >> v[i][j];

    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            if(consistent(i,j,v)) ans++;
        }
    
    fin.close();
    ofstream fout("gymnastics.out");
    fout << ans << endl;
    fout.close();

}