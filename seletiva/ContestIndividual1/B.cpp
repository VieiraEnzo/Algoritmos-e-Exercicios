#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int N, M; cin >> N >> M;
    vector<pair<int,set<int>>> prod;
    for(int i=0; i < N; i ++){
        int price, C, temp;
        set <int> functions;
        cin >> price >> C;
        for(int j =0; j < C; j ++){
            cin >> temp;
            functions.insert(temp);
        }
        prod.push_back(make_pair(price,functions));
        sort(prod.begin(),prod.end());
    }
    
    vector<int> result;
    for(int i = 0; i < N-1; i ++){
        for(int j = i+1; j < N; j ++){
            set_intersection(prod[i].second.begin(),prod[i].second.end(),prod[j].second.begin(),prod[j].second.end(),result.begin());
            if(result.size() == prod[j].second.size()){
                cout << "Yes";
                return 0;
            }
            
        }
    }

}
    