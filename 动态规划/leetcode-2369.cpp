class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int l = nums.size();
        vector<bool> dp(l+1);
        dp[0] = true;
        for (int i = 1; i < l; i++)
            dp[i+1] = (dp[i-1] && nums[i] == nums[i-1]) ||
                    (i > 1 && dp[i-2] && nums[i] == nums[i-1] && nums[i] == nums[i-2]) ||
                    (i > 1 && dp[i-2] && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2);
        return dp[l];
    }
};