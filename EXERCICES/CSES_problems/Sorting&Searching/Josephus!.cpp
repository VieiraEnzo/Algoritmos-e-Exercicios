#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int jump = 2;
    int jogadas = 0;
    int player = 0;
    int start_player = 2;

    //h[0] = s[0]
    // h[1] = s[0] * p + s[1]
    //s[n] * p^n + ... + p * s[1] + s[0]
    //s[0] * p ^n+ ... + p * s[n-1] * s[n]
    //range(a, b) = h[b] - [a] * p[b-a]
    //[0,1)
 
    for(int i = 0; i< n; i++){

        player = start_player;

        while (player + jump < n)
        {
            player += jump;
            cout << player;
            i++;
        }
        


        
    }
    
}