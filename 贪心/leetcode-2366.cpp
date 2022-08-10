class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        reverse(nums.begin(), nums.end());
        int m = nums[0];
        for (int n : nums) {
            int k = (n + m - 1) / m - 1; // 拆分成k个m和一个余数，要拆多少次
            res += k;
            m = n / (k+1);
        }
        return res;
    }
};