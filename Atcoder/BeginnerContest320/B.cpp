#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
string s;

int palindrome(int i, int j)
{
    int l = i;
    int r = j;
    while(i<j)
    {
        if(s[i] == s[j])
        {
            i++;j--;
        }
        else{
            return 0;
        }
    }
    return (r-l);
}

int main(){
    fastio;
    cin >> s;
    int n = s.size();

    int res = 0;
    for(int i =0; i < n; i++)
        for(int j = n-1; j > i; j--)
            res = max(res, palindrome(i,j));

    cout << res +1 << endl;
    

}