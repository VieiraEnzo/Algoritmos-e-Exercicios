#include <bits/stdc++.h>
using namespace std;

bool is_paranoid(string number);
bool is_paranoid_front(string number);
bool is_paranoid_secound(string number);

bool is_paranoid(string number){
    if(number.size() == 1){
        return true;
    }
    if(number.size() == 2){
        if(number[0] == number[1]){return false;}
        return true;
    }
    bool all_equal = true;
    for(int i=0;i<number.size();i++){
        if(i != i){
            all_equal = false;
            break;
        }
    }
    if(all_equal){return false}
    else{return is_paranoid_front(number) || is_paranoid_secound(number);}
}

bool is_paranoid_front(string number){
    string substring;
    if(number.size() == 3){
        if(number[0] == number[1]){return false;}
        substring.push_back(number[1]);
    }

    int prev = 0;
    for(int i=2;i < number.size() -1; i=i+2){
        if(number[i] != number[prev] && number[i+1] != number[prev+1]){
            substring.push_back(number[i+1]);
            prev = i + 2;
        }
    }



    if(number.size() % 2 != 0){substring.push_back(number[number.size()-1]);}
    return is_paranoid(substring);
}

bool is_paranoid_secound(string number){
    string substring;
    if(number.size() == 3){
        if(number[1] == number[2]){return false;}
        substring.push_back(number[0]);
        substring.push_back(number[2]);
    }
    if(number.size() == 4){
        if(number[1] == number[2]){return false;}
        substring.push_back(number[0]);
        substring.push_back(number[2]);
    }

    int prev = 1;
    substring.push_back(number[0]);
    for(int i=3;i < number.size() -1; i=i+2){

        if(number[i] != number[prev] && number[i+1] != number[prev+1]){
            substring.push_back(number[i+1]);
            prev = i + 2;
        }
    }
    if(number.size() % 2 == 0){substring.push_back(number[number.size()-1]);}

    return is_paranoid(substring);
}


int main(){
    long long int t;
    cin >> t;
    long long size;
    string number;
    for(int init = 0;init < t; init++){
        cin >> size >> number;


        for(int i =0; i < number.size() -1; i++){
            for(int j=i+1;j < number.size();j++){
                if(is_paranoid(number.substr(i,j-i+1))){
                    size ++;
                } 
            }
        }
        cout << size << endl;

    }
}
