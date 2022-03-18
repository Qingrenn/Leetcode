class Solution {
    int mem[46] = {0};
public:
    int climbStairs(int n) {
        int ans = dfs(n, 0);
        return ans;
    }

    int dfs(int n, int state) {
        int ans = 0;
        if (state > n)  return 0;
        if (state == n) return 1;
        if (mem[state]) ans += mem[state];
        else {
            ans += dfs(n, state+1);
            ans += dfs(n, state+2);
            mem[state] = ans;
        }
        return ans;
    }
};

/*
记忆化搜索
*/