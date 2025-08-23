    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        //mínimo de doses nescessarias
        int md = ((c-b) + (d-1))/d;

        //máximo de doses possíveis
        int Md = (c-a)/d;

        if(Md < md){
            cout << "N\n";
        }else{
            cout << "S\n";
        }
        
    }