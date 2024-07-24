#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

char bestType;

vector<string> MainHand;
vector<string> otherHand;

void getbest(set<int> &A, int capacidade, char tipo){
    
    while(!A.empty() && capacidade > 0){
        capacidade--;
        int res = *(--A.end());
        A.erase(--A.end());
        string morte = to_string(res) + tipo;
        MainHand.push_back(morte);  
    }

    while(!A.empty()){
        int res = *(--A.end());
        A.erase(--A.end());
        string morte = to_string(res) + tipo;
        otherHand.push_back(morte);  
    }
}

void getbest2(set<int> &A, int capacidade, char tipo){

    int tamanho = A.size();
    
    while(A.size() > (tamanho+1)/2 && capacidade > 0){
        capacidade--;
        int res = *(--A.end());
        A.erase(--A.end());
        string morte = to_string(res) + tipo;
        MainHand.push_back(morte);  
    }

    while(!A.empty()){
        int res = *(--A.end());
        A.erase(--A.end());
        string morte = to_string(res) + tipo;
        otherHand.push_back(morte);  
    }
}

string getBestCard(string S){

    for(auto i = otherHand.begin(); i != otherHand.end(); i++){
        string card = *i;
        if(card[2] == bestType) continue;
        if(card[2] == S[2] && card[1] < S[1]){
            otherHand.erase(i);
            return card;
        }
    }

    for(auto i = otherHand.begin(); i != otherHand.end(); i++){
        string card = *i;
        if(card[2] != bestType || card[1] > S[2]) continue;
        otherHand.erase(i);
        return card;
    }

    return "morte";
}

void solve(){
    MainHand.clear();
    otherHand.clear();

    int n; cin >> n;
    char s; cin >> s;
    bestType = s;
    set<int> C,D,H,S;

    for(int i = 0; i < 2*n; i++){
        string k; cin >> k;
        pr(k);
        string morte; morte.push_back(k[0]);
        if(k[1] == 'C') C.insert(stoi(morte));
        if(k[1] == 'D') D.insert(stoi(morte));
        if(k[1] == 'H') H.insert(stoi(morte));
        if(k[1] == 'S') S.insert(stoi(morte));
    }

    pr(C,D,H,S);

    if(s == 'C') getbest(C, n, 'C');
    else if(s == 'D') getbest(D, n, 'D');
    else if(s == 'H') getbest(H, n, 'H');
    else getbest(S, n, 'S');

    getbest2(C, n - MainHand.size(), 'C');
    getbest2(D, n - MainHand.size(), 'D');
    getbest2(H, n - MainHand.size(), 'H');
    getbest2(S, n - MainHand.size(), 'S');

    sort(MainHand.begin(), MainHand.end());
    sort(otherHand.begin(), otherHand.end());

    pr(MainHand);
    pr(otherHand);

    if(MainHand.size() != otherHand.size()) {cout << "IMPOSSIBLE\n"; return;}

    for(auto card : MainHand){
        string other = getBestCard(card);
        cout << other << " " << card << "\n";
    }

}

int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}