class Solution {
    int trie[30010][26], cnt[30010], idx=0, maxlength=0;
public:
    struct cmp{
            bool operator() (const string s1, const string s2) const{
                if ( s1.length() != s2.length() )   return s1.length() < s2.length();
                else return s1 > s2;
            }
    };

    string longestWord(vector<string>& words) {
        memset(trie, 0x00, sizeof trie);
        memset(cnt, 0x00, sizeof cnt);

        for(string s : words)   insert(s);

        priority_queue<string, vector<string>, cmp>  heap;
        string path = "";
        heap.push(path);
        int start_p = 0;
        search(0, heap, path);

        return heap.top();
    }

    void insert(string s) {
        int p = 0;
        for (char c : s) {
            int i = c - 'a';
            if (!trie[p][i]) trie[p][i] = ++idx;
            p = trie[p][i];
        }
        cnt[p]++;
    }

    void search(int p, priority_queue<string, vector<string>, cmp>&  heap, string path) {
        
        for (int i = 0; i < 26; i++){
            if (trie[p][i] == 0) continue;
            if (trie[p][i] && !cnt[trie[p][i]]) continue;
            if (trie[p][i] && cnt[trie[p][i]]) {
                string backup = path;
                path += 'a' + i;
                heap.push(path);
                search(trie[p][i], heap, path);
                path = backup;
            }
        }
        return;
    }

};

/*
这道题解法比较暴力，创建Trie树然后DFS搜索出所有情况，通过维护一个堆来实现找到目标字符串。
*/