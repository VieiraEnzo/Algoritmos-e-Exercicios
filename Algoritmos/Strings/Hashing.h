// Algoritmo de Hashing de Strings
//Complexidade: O(n), onde n é o tamanho da string

//Cria o hashing de uma string
//ha[0] = 0
//ha[1] = s[0]
//ha[2] = p*s[0] + s[1]
//ha[3] = p^2*s[0] + p*s[1] + s[2]


template<int MOD> struct Hashing{
    ll base, n;
    vector<ll> pow, ha; 

    /*
    for random base:
    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);
    */

    Hashing(string & s, int a) : n(s.size()), base(a) ,pow(n+1), ha(n+1){

        pow[0] = 1;
        for(int i = 0; i < n; i++){
            ha[i+1] = (ha[i] * base + s[i])%MOD;
            pow[i+1] = (pow[i] * base)%MOD;
        }
    }
    
    //Retorna o Hashing da substring [a, b), indexado em 0
    int getRange(int a, int b){
        assert(a <= b);
        ll hash =  (ha[b] - (ha[a] * pow[b-a])%MOD)%MOD;
        return hash < 0 ? hash + MOD : hash;
    }
    
};