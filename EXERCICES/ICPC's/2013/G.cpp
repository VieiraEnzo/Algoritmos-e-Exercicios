#include <bits/stdc++.h>
using namespace std;

int find_min(vector<int> &v){

    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        while (v[i] != i)
        {
            swap(v[i], v[v[i]]);
            ans++;
        }
    }

    return ans;
}

int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);
    int l, c; cin >> l >> c;
    vector<vector<int>> mat(l, vector<int> (c));

    vector<int> colum;
    vector<int> line;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> mat[i][j];
            if(i == 0){colum.push_back(mat[i][j]);}
            if(j == 0){line.push_back (mat[i][j]);}
        }
    }

    for(int i =0; i < l; i++){
        int mine = 1e9, mane = 0;
        for(int j = 0; j < c; j++){
            mine = min(mine, mat[i][j]);
            mane = max(mane, mat[i][j]);
        }
        if(mane!= mine + c -1){
            cout << "*" <<endl;
            return 0;
        }
    
    }

    for(int i = 0; i < c; i++){
        for(int j = 1; j < l; j++){
            if(mat[j][i]%c != mat[j-1][i]%c){
                cout << "*" << endl;
                return 0;
            }
        }
    }

    
    int me = *min_element(colum.begin(), colum.end());
    for(int i = 0; i < c; i++) colum[i] -= me;

    for(int i = 0; i < l; i++) line[i] = (line[i]-1)/c;

    int ans = find_min(colum) + find_min(line);


    cout << ans << "\n";

}