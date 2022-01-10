/*
DFS
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bool state[210] = {false};
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!state[i]) {
                dfs(isConnected, i, state);
                res++;
            } 
        }
        return res;
    }

    void dfs (vector<vector<int>>& isConnected, int node, bool* state) {
        state[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !state[i])
                dfs(isConnected, i, state);
        }
        return;
    }

};

/*
并查集
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int p[210];
        int n = isConnected.size();
        for (int i = 1; i <= n; i++)
            p[i] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (isConnected[i-1][j-1] == 1 && i != j) {
                    int a = find(i, p), b = find(j, p);
                    p[b] = a;
                }
            }
        }

        unordered_map<int, int> h;
        for (int i = 1; i <= n; i++)
            h[find(p[i], p)]++;
    
        return h.size();
    }

    int find (int x, int p[]) {
        if (p[x] != x)  p[x] = find(p[x], p);
        return p[x];
    }

};
