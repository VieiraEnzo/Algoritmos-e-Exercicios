#include <bits/stdc++.h>
using namespace std;

int main(){

    int a;
    string bits;
    cin >> bits;
    for(int i = 0; i < bits.size(); i++)
        cout << !(bits[i] - '0');
}
