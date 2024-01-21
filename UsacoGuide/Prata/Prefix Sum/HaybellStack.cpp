#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;


int main()
{
    fastio;
    ifstream fin("stacking.in");
    int n, k; 
    cin >> n >> k;
    // fin >> n >> k;
    vector<int> freq(n,0);
    while (k--)
    {
        int l,r ; cin >> l >> r;
        freq[l-1]++;
        freq[r]--;
    }
    int sum = 0;
    vector<int> v;
    for(int i = 0 ; i < n; i++)
    {
        sum += freq[i];
        v.push_back(sum);
    }

    sort(v.begin(), v.end());
    cout << v[(n/2)] << endl;
    
    
    ofstream fout("stacking.out");
    // fout << v[(n/2) + 1] << endl;
    fin.close();
    fout.close();
}