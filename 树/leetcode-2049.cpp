class Solution {
    int N;
public:
    int countHighestScoreNodes(vector<int>& parents) {
        N = parents.size();
        vector<vector<int>> node2child(N, vector<int>());
        for (int c = 1; c < N; c++) {
            int p = parents[c];
            node2child[p].push_back(c);
        }
        int cnt = 0;
        long long maxValue = 0;
        int _ = dfs(0, node2child, maxValue, cnt);
        return cnt;
    }

    int dfs(int node, vector<vector<int>> &node2child, long long &maxValue, int &cnt) {
        int childNum[2] = {0, 0};
        for (int i = 0; i < node2child[node].size(); i++)
            childNum[i] = dfs(node2child[node][i], node2child, maxValue, cnt);
        int childSum = childNum[0] + childNum[1];
        long long value = (long long) max(childNum[0], 1) * max(childNum[1], 1) * max((N - childSum - 1), 1);
        if (value > maxValue) {
            maxValue = value;
            cnt=1;
        }else if (value == maxValue)
            cnt++;
        return childSum + 1;
    }

};