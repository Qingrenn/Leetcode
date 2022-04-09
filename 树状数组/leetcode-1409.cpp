class Solution {
private:
    int N;
    int tree[2010] = {0};
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int a) {
        for (int i = x + 1; i < N; i += lowbit(i))
            tree[i] += a;
    }
    int query(int x) {
        int ans = 0;
        for (int i = x + 1; i > 0; i -= lowbit(i))
            ans += tree[i];
        return ans;
    }

public:
    vector<int> processQueries(vector<int>& queries, int m) {
        N = queries.size() + m + 1;
        vector<int> P2index(m+1);
        for (int i = queries.size(), j = 1; j <= m; i++, j++) {
            P2index[j] = i;
            add(i, 1);
        }
        
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i], curIndex = P2index[q], nextIndex = queries.size() - 1 - i;
            res.push_back(query(curIndex) - 1);
            add(curIndex, -1);
            add(nextIndex, 1);
            P2index[q] = nextIndex;
        }
        return res;

    }
};