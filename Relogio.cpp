#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, m, s; cin >> h >> m >> s;
    int t; cin >> t;

    t += s;
    t += m * 60;
    t += h * 3600;

    int RespSegungos = t % 60;
    t /= 60;
    int RespMinutos = t % 60;
    t /= 60;
    int RespHora = t % 24;

    cout << RespHora << "\n" << RespMinutos << "\n" << RespSegungos << "\n";
}