class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int dp[26]={0};
        int k=1;
        for (int i = 0; i < p.length(); i++) {
            if (i && (p[i] - p[i-1] + 26) % 26 == 1){
                k++;
            }else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp, dp + 26, 0);
    }
};

/**
 * @brief 
 * 满足题意的子串，按结尾的字符枚举。
 */