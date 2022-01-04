/*
没必要维护一个前缀和数组
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int N = nums.size() + 1;
        int prefix_sum[N];
        prefix_sum[0] = 0;
        for (int i = 1; i < N; i++)
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];

        int res = N;
        for (int r = 1, l = 0; r < N; r++) {
            while (prefix_sum[r] - prefix_sum[l] >= target) {
                res = min(r - l, res);
                l++;
            }
        }
        if (res == N)
            return 0;
        return res;
    }
};

/*
动态维护左右两个指针即可
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, res = n + 1;
        for (int r = 0, l = -1; r < n; r++) {
            sum += nums[r];
            while(sum - nums[l+1] >= target){
                l++;
                sum -= nums[l];
            }   
            if (sum >= target)   res = min(r - l, res);
        }
        if (res == n + 1) return 0;
        return res;
    }
};