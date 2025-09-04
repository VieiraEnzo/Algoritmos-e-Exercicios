#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
const i64 inf = 1e18;

int rnd(int a, int b){
    return a + rand() % (b-a+1);
}

//Generate test Cases
int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    int n = rnd(1, 100);
    int k = rnd(1, 1e9);
    cout << 1 << "\n";
    cout << n << " " << k << "\n";
    for(int i = 0; i < n; i++){
        cout << rnd(1, 1e9) << " ";
    }
    cout << "\n";
    return 0;
}