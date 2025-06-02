vector<int> kmp(string t, string p){
    
    vector<int> pi= find_pi(p + '$'), match;
    for(int i = 0, j = 0; i < t.size(); i++){
        while(j > 0 && t[i] != p[j]) j = pi[j-1];
        if(t[i] == p[j]) j++;
        if(j == p.size()) match.push_back(i-j+1);
    }
    return match;
};

struct autKMP {
    vector<vector<int>> nxt;

    autKMP(string& s) : nxt(26, vector<int>(s.size()+1)) {
        vector<int> p = pi(s);
        nxt[s[0]-'a'][0] = 1;
        for (char c = 0; c < 26; c++)
            for (int i = 1; i <= s.size(); i++)
                nxt[c][i] = c == s[i]-'a' ? i+1 : nxt[c][p[i-1]];
    }
};
