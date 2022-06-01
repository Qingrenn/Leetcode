class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> st;
        int ans = 0;
        for (int n : nums) {
            int max_t = 0;
            while (st.size() && st.top().first <= n) {
                max_t = max(st.top().second, max_t);
                st.pop();
            }
            if (st.size())
                max_t += 1;
            ans = max(ans, max_t);
            st.push(make_pair(n, max_t));
        }
        return ans;
    }
};

/**
 * @brief 
 * 挖掘题意的性质，使用单调栈维护递减序列
 */