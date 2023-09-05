#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,c;
    int num[3];
    cin >> n >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    int resto_menor = n % num[0];
    if(num[1] - resto_menor % num[0] == 0){
        cout << n/num[0] - (num[1] - resto_menor / num[0]) + 1;
    }
}