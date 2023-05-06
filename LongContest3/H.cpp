#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    long long int N, max_L = -1,count = 0;
    cin >> N;
    cin >> S;
    for(int i=0; i < N; i ++){
        if(S[i] == 'o'){
            count ++;
        }
        if(S[i] == '-'){
            if(count > max_L && count > 0){max_L = count;}
            count = 0;
        }
        if(i == N-1){if(count > max_L && count > 0 && S[N-1-count] == '-'){max_L = count;}}
    }
    cout << max_L;

}
