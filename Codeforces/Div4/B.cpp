#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
char table[3][3];

void solve()
{
    for(int i =0; i < 3 ; i++)
        for(int j = 0; j < 3; j++)
            cin >> table[i][j];

    for(int i =0; i < 3 ; i++)
        for(int j = 0; j < 3; j++)
            if(table[i][j] == '?')
            {
                if(j == 0)
                {
                    if(table[i][1] != 'A' && table[i][2] != 'A') cout << 'A' << endl;
                    if(table[i][1] != 'B' && table[i][2] != 'B') cout << 'B' << endl;
                    if(table[i][1] != 'C' && table[i][2] != 'C') cout << 'C' << endl;
                }
                if(j == 1)
                {
                    if(table[i][0] != 'A' && table[i][2] != 'A') cout << 'A' << endl;
                    if(table[i][0] != 'B' && table[i][2] != 'B') cout << 'B' << endl;
                    if(table[i][0] != 'C' && table[i][2] != 'C') cout << 'C' << endl;
                }
                if(j == 2)
                {
                    if(table[i][1] != 'A' && table[i][0] != 'A') cout << 'A' << endl;
                    if(table[i][1] != 'B' && table[i][0] != 'B') cout << 'B' << endl;
                    if(table[i][1] != 'C' && table[i][0] != 'C') cout << 'C' << endl;
                }
                return;
            }

}



int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}