/*DFS 暴力会超时*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        const int N = n, M = 2*n;
        int e[M], ne[M], h[N], idx = 0;

        memset(h, -1, sizeof h);
        for (vector<int> ab : edges) {
            int a = ab[0], b = ab[1];
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
            e[idx] = a, ne[idx] = h[b], h[b] = idx++;
        }

        vector<int> res;
        int min_height = n - 1;
        for (int i = 0; i < n; i++) {
            bool state[N];
            memset(state, false, sizeof state);
            state[i] = true;
            int height = dfs(i, state, e, ne, h, min_height, 0);
            // cout << height << endl;
            if ( height < min_height) {
                min_height = height; res.clear(); res.push_back(i);
            }else if (height == min_height)
                res.push_back(i);
        }

        return res;
    }

    int dfs(int node, bool state[], int e[], int ne[], int h[], int min_height, int cur_depth) {
        if (cur_depth > min_height) return cur_depth;
        int height = 0;
        for (int i = h[node]; i != -1; i = ne[i]) {
            int j = e[i];
            if (state[j])   continue;
            state[j] = true;
            height = max(dfs(j, state, e, ne, h, min_height, cur_depth + 1) + 1, height);
            if (height > min_height)    break;
        }
        return height;
    }

};

/*
BFS: https://leetcode-cn.com/problems/minimum-height-trees/solution/zui-rong-yi-li-jie-de-bfsfen-xi-jian-dan-zhu-shi-x/
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if ( n == 1) {
            vector<int>  res = {0};
            return res;
        }
        const int N = n, M = 2*n;
        int e[M], ne[M], h[N], d[N], idx = 0;

        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);
        for (vector<int> ab : edges) {
            int a = ab[0], b = ab[1];
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
            e[idx] = a, ne[idx] = h[b], h[b] = idx++;
            d[a]++, d[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (d[i] == 1)
                q.push(i);

        vector<int> res;
        while (q.size()) {
            res.clear();
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int f = q.front(); q.pop();
                res.push_back(f);
                for (int i = h[f]; i != -1; i = ne[i]) {
                    int j = e[i];
                    d[j] -- ;
                    if (d[j] == 1)
                        q.push(j);
                }
            }
        }

        return res;
    }

};