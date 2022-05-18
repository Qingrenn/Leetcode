class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cnt[32]={0};
        for (int c : candidates) {
            for (int i = 0; i < 32; i++) {
                if ((c & (1 << i)) > 0)   cnt[i]++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++)
            res = max(cnt[i], res);
        return res;
    }
};

/**
 * @brief 
 * https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/solution/by-hu-li-hu-wai-6kum/
 * 位运算大于0的最长序列，就是某一位为0次数最大的那个值
 */