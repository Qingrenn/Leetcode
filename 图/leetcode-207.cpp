class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int N = numCourses, M = prerequisites.size();
        if (M == 0)
            return true;
        
        int e[M], ne[M], h[N], d[N], idx = 0;

        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);

        for (auto v : prerequisites) {
            e[idx] = v[0], ne[idx] = h[v[1]], h[v[1]] = idx++;
            d[v[0]]++;
        }
            
        // toposort
        int q[N], hh = 0, tt = -1;
        for (int i = 0; i < N; i++)
            if (d[i] == 0)
                q[++tt] = i;
        
        while (hh <= tt) {
            int t = q[hh++];
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                d[j]--;
                if (d[j] == 0)
                    q[++tt] = j;
            }
        }

        return tt + 1 == numCourses;

    }
};

/*
这道题可以抽象成有向图判断是否存在环的问题。
有向图中是否存在环有多种解法：
- 拓扑排序 ✅
- DFS
- 并查集

https://blog.csdn.net/qq_38943651/article/details/108396570
*/