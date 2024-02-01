#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll N, K; cin >> N >> K;
    vector<pair<ll,ll>> medicine(N);
    ll total_sum_pills = 0;
    for(ll i =0; i < N; i++){
        ll temp, temp2;
        cin >> temp >> temp2;
        total_sum_pills += temp2;
        medicine[i] = make_pair(temp,temp2);
    }

    sort(medicine.begin(), medicine.end());
    if(total_sum_pills <= K){cout << 1; return 0;}
    for(ll i=0;i<N;i++){
        if(total_sum_pills - medicine[i].second <= K){
            cout << medicine[i].first + 1;
            break;
        }
        else{
            total_sum_pills -= medicine[i].second;
        }
    }
}
    