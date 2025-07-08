//Estrutura de dados Trie para armazenar strings

struct Vertex {
    int next[K];
    ll output = 0;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

struct Trie{

    int n;
    const int K = 26;
    vector<Vertex> t;

    Trie() : t(1){}

    void add_string(string s){
        int p = 0;
        for(int i = 0; i < s.size(); i++){
            if(t[p].next[s[i] - 'a'] == -1){
                t[p].next[s[i] - 'a'] = t.size();
                t.push_back(Vertex());
            }
            p = t[p].next[s[i] - 'a'];
        }
        t[p].output++;
    }
};