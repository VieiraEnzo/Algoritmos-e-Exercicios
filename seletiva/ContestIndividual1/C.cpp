#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int N, M ; cin >> N >> M;
    vector<string> eaten(N);
    vector<string> menu(M);
    int standard_price, temp;
    string temp_string;
    map<string,int> prices;
    for(int i =0; i< N; i ++) cin >> eaten[i];
    for(int i =0; i< M; i ++) cin >> menu[i];
    cin >> standard_price;
    for(int i = 0; i < M; i ++){
        cin >> temp;
        prices[menu[i]] = temp;
    }

    int total = 0;
    for(int i =0; i< N; i ++){
        if(prices.find(eaten[i]) != prices.end()){
            total += prices[eaten[i]];
        }
        else{
            total+= standard_price;
        }
    }
    cout << total;

}
    