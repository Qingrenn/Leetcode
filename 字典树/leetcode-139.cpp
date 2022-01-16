class Solution {
    int idx = 0;
    int trie[20010][26], cnt[20010];
    bool memo[310] = {false};
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(trie, 0, sizeof trie);
        memset(cnt, 0, sizeof cnt);
        for (string i : wordDict)   insert(i);
        return dfs(s, 0);

    }

    void insert(string s) {
        int i = 0;
        for (char c : s) {
            int j = c - 'a';
            if ( !trie[i][j] )  trie[i][j] = ++idx;
            i = trie[i][j];
        }
        cnt[i]++;
        return;
    }

    bool dfs(string s, int pos) {
        if (memo[pos])  return false;
        if (pos == s.size())    return true;
        int k = 0;
        for (int i = pos; i < s.size(); i++) {
            int j = s[i] - 'a';
            if (trie[k][j]) {
                k = trie[k][j];
                if (cnt[k] && dfs(s, i + 1))
                    return true;
            }else
                break;
        }
        memo[pos] = true;
        return false;
    }

};

/*
创建Trie树后再遍历，要对DFS做记忆化，否则会超时。
*/