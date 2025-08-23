struct BinLift
{

    int n;
    vector<vector<int>> jmp;

    BinLift(int n): n(n), jmp(32, vector<int> (n+1)) {}

    void set_jmp(int i, int node){
        jmp[0][i] = node;
    }

    void build(){
        for(int i = 1; i < 32; i++){
            for(int j = 1; j <= n; j++){
                jmp[i][j] = jmp[i-1][jmp[i-1][j]];
            }
        }
    }

    int get_jump(int node, int dif){

        for(int i = 0; i < 32; i++){
            if(1<<i & dif){
                node = jmp[i][node];
            }
        }
        
        return node;
    }
    
};