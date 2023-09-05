#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int N; cin >> N;
    N++;
    vector<int> graph(N);
    set<int> visited;
    for(int i =1; i < N; i ++) cin >> graph[i];
    bool found = false;
    vector<int> anw;

        int now = 1;
        int prox;
        anw.push_back(now);
        while (true)
        {
            prox = graph[now];
            if(visited.find(prox) == visited.end()){
                visited.insert(prox);
                anw.push_back(prox);
                now = prox;
            }
            else{
                break;
            }
        }
        //}
        int com;
        for(int i = anw.size()-1; i >=1; i--){
            if(anw[i] == prox){
                com = i;
                break;
            }
        }

        cout << anw.size() - com << endl;
        for(com;com < anw.size(); com++){
            cout << anw[com] << " ";
        }
        

        
}

    