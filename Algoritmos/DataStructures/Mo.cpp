template<typename T> struct Mo{
    //TODO: declare the data structures
    Mo(){

    }

    void add(int idx){
        //TODO: add an element to the data structure
    }  

    void remove(int idx){
        //TODO: remove an element from the data structure
    }     

    int get_answer(){
        //TODO: get answer from the data structure
    }  

    vector<int> solve(vector<Query> queries) {
        vector <int> answers(queries.size());
        sort(queries.begin(), queries.end());

        //TODO: initialize data structue
        
        int cur_l = 0;
        int cur_r = -1;
        for (Query q : queries) {
            while (cur_l > q.l) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < q.r) {
                cur_r++;
                add(cur_r);
            }
            while (cur_l < q.l) {
                remove(cur_l);
                cur_l++;
            }
            while (cur_r > q.r) {
                remove(cur_r);
                cur_r--;
            }
            answers[q.idx] = get_answer();
        }
        return answers;
    }
};


const int blockSize = 500;

struct Query
{
    int l, r, idx;

    bool operator<(Query other) const{
        return make_pair(l/blockSize, r) < make_pair(other.l/blockSize, other.r);
    };
};


struct Mos{

    int q, cur_l = 0, cur_r = -1;
    vector<int> answers;
    vector<Query> queries;

    Mos(int q) : queries(q), q(queries.size()), answers(q) {}

    void add_query(int l, int r, int ind){
        queries[ind] = {l,r,ind};
    };

    int ans = 0;
    void remove(int i){
        //...
    }
    void add(int i){
        //...
    }
    int getAns(){
        //...
    }

    vector<int> run(){

        for(auto Q : queries){
            
            while(cur_l > Q.l){
                cur_l--;
                add(cur_l);
            }

            while(cur_r < Q.r){
                cur_r++;
                add(cur_r);
            }

            while(cur_l < Q.l){
                remove(cur_l);
                cur_l++;
            }

            while(cur_r > Q.r){
                remove(cur_r);
                cur_r--;
            }

            answers[Q.idx] = getAns();

        }  

        return answers;
    }

};