#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;


int main()
{
    fastio;
    ifstream fin("gymnastics.in");
    string st;
    fin >> st;
    //cin >> st;

    vector<int> vis(26);
    vector<int> entrada(52, 0);
    for(int i = 0; i < st.size(); i++)
        {
            if(!vis[st[i] - 'A']){
                entrada[i] = 1;
                vis[st[i] - 'A'] = 1;
            }
        }



    int ans = 0;
    map<char,int> mp;
    for(char a = 'A'; a <= 'Z'; a++)
    {
        bool start = false;
        mp.clear();
        for(int i = 0; i < st.size(); i++)
        {
            if(!start && st[i] == a){start = true;continue;}
            if(start)
            {   
                if(st[i] == a){break;}
                if(mp[st[i]]) ans--;
                else if(entrada[i] && mp[st[i]] == 0)
                {ans++;mp[st[i]]++;}
                
                
            }
        }   
    }




    ofstream fout("gymnastics.out");
    fout << ans << endl;
    //cout << ans;
    fin.close();
    fout.close();

}