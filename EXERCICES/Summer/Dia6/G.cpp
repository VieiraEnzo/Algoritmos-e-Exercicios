#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k; cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> fila;

    int sum = 0;
    int minsum = 0;
    for(int i = 0; i< n; i++){
        int a; cin >> a;
        //multiplo de k
        if(sum >= k){
            sum -= k;
            fila.push(a);
        }
        else{
            if(!fila.empty() &&  a > fila.top()){
                minsum += fila.top();
                fila.pop();
                fila.push(a);
            }else{
                minsum += a;

            }
            sum++;
        }
        // cout << i <<": " << sum << endl;
    }

    cout << minsum << endl;
    // while (!fila.empty())
    // {
    //     cout << fila.top() << " ";
    //     fila.pop();
    // }cout << endl;
    
}