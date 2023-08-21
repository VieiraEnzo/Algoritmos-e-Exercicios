#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(3);
    for(int i=0; i<3;i++)cin >> v[i];
    set<int> s;

    //achar quantas vezes apertou
    int i=0;
    s.insert(0);
    while (true)
    {
        i = v[i];
        if(s.find(i) != s.end()){break;}
        s.insert(i);
    }
    cout << s.size() << endl;
    
    //Achar tamanho do ciclo interno
    int k =3;
    i=0;
    s.clear();
    while (k)
    {
        i = v[i];
        k--;
    }
    s.insert(i);
    while (true)
    {
        i = v[i];
        if(s.find(i) != s.end()){break;}
        s.insert(i);
    }
    int cicle = s.size();


    //achar aonde para
    int a_mais;
    i=0;
    if(n>=3){
        a_mais = (n-3)%cicle;
        k = 3 + a_mais;
    }
    else{k = n;}
    while(k)
    {
        i = v[i];
        k--;
    }
    cout << i;

}   