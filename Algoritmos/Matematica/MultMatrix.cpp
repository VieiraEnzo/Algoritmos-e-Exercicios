//id : matriz identidade
//expo - expoente da metriz
//base: {{1},{1},{1}} (formato da base)



template<typename T> struct Matriz
{
    
    vector<vll> mult_matriz(vector<vll> a, vector<vll> b,){
        vector<vll> z(a.size());

        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b[0].size(); j++){
                ll sum = 0;
                for(int k = 0; k < a[0].size(); k++){
                    sum += mod(a[i][k] * b[k][j], MOD);
                    sum=mod(sum,MOD);
                }
                z[i].push_back(mod(sum,MOD));
            }
        }
        return z;
    }

    vector<vll> recorrencia_matriz(int expo, vector<vll> base, vector<vll> A){
    
        vll digits(0);

        while (expo > 1){
            digits.push_back(expo%2); expo/=2;
        }
        digits.push_back(expo);

        vector<vll> id = {{1,0,0}, {0,1,0}, {0,0,1}};

        for(auto x : digits){
            if(x == 1){
                id = mult_matriz(A,A);
            }
        }
        id = mult_matriz(id, base);

        return id;
    
    }
    
};
