#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    if(s.size() < 4){
        cout << s << endl;
    }else if(s.size() == 4)
    {
        if(s[1] == '0'){cout << s[0] << 'K' << endl;}
        else cout << s[0] << '.' << s[1] << 'K' << endl;
    }
    else if(s.size() == 5){
        cout << s.substr(0,2) << 'K' << endl;
    }
    else if(s.size() == 6){
        cout << s.substr(0,3) << 'K' << endl;
    }
    else if(s.size() == 7){
        if(s[1] == '0'){cout << s[0] << 'M' << endl;}
        else cout << s[0] << '.' << s[1] << 'M' << endl;
    }
    else if(s.size() == 8){
        cout << s.substr(0,2) << 'M' << endl;
    }
    else if(s.size() == 9){
        cout << s.substr(0,3) << 'M' << endl;
    }
    else if(s.size() == 10){
        if(s[1] == '0'){cout << s[0] << 'B' << endl;}
        else cout << s[0] << '.' << s[1] << 'B' << endl;
    }
    else if(s.size() == 11){
        cout << s.substr(0,2) << 'B' << endl;
    }
    else if(s.size() == 12){
        cout << s.substr(0,3) << 'B' << endl;
    }


}