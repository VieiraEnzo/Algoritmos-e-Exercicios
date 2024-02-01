#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int H,W; cin >> H >> W;
    vector<string> v(H);
    vector<pair<int,int>> sqr(4);
    for(int i=0; i < H; i++) cin>> v[i];

    bool top_left = false;
    for(int i=0; i< H; i++){
        for(int j =0; j < W; j++){
            if(v[i][j] == '#'){
                if(!top_left){
                    sqr[0] = make_pair(i,j);
                    top_left = true;
                }
                sqr[1] = make_pair(i,j);
            }
        }
        if(top_left) break;
    }

    bool bot_left = false;
    for(int i=H-1; i>=0; i--){
        for(int j =0; j < W; j++){
            if(v[i][j] == '#'){
                if(!bot_left){
                    sqr[3] = make_pair(i,j);
                    bot_left = true;
                }
                sqr[4] = make_pair(i,j);
            }
        }
        if(bot_left) break;
    }

    if((sqr[4].first - sqr[0].first) * (sqr[4].second - sqr[0].second) > (sqr[3].first - sqr[1].first) * (sqr[1].second - sqr[3].second)){
        for(int i = sqr[0].first; i <= sqr[4].first; i++){
            for(int j = sqr[0].second; j <= sqr[4].second; j++){
                if(v[i][j] == '.'){
                    cout << i + 1 << " " << j+1;
                    return 0;
                }
            }
        }
    }
    else{
        for(int i = sqr[1].first; i <= sqr[3].first; i++){
            for(int j = sqr[3].second; j <= sqr[1].second; j++){
                if(v[i][j] == '.'){
                    cout << i + 1 << " " << j+1;
                    return 0;
                }
            }
        }
    }

    


}
    