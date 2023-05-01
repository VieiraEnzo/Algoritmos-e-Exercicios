#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int t,n;
    cin >> t;
    vector<int> vec;
    vector<int> answer;
    int num;

    for(int init = 0; init < t; init ++){

        cin >>n;
        answer.clear();
        vec.clear();
        for(int i=0; i<n-1; i++){
            cin >> num;
            vec.push_back(num);
        }

        bool first = true;
        for(int i = 0; i < n-2; i ++){

            if(vec[i] < vec[i+1] && i == 0){
                answer.push_back(vec[i]);
                answer.push_back(0);
                first = false;
            }

            else if(vec[i] < vec[i+1] && first && i != 0){
                answer.push_back(0);
                answer.push_back(vec[i]);
                first = false;
            }

            else if(vec[i] < vec[i+1] && !first){
                answer.push_back(vec[i]);
            }

            else if(vec[i] == vec[i+1]){
                answer.push_back(vec[i]);
            }

            else if(vec[i] > vec[i+1]){
                answer.push_back(vec[i]);
            }
            
        }
        answer.push_back(vec[vec.size() - 1]);
        for(int i = 0; i < n - answer.size(); i ++){
            answer.push_back(0);
        }
        // se diferente do tamanho adicionar 0 no final
        for(int i=0;i<n;i++){
            cout << answer[i] << ' ';
        }
        cout << endl;
        
    }
}
