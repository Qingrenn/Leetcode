// 随着窃取能力的下降，能打劫房屋的数目也会减少。-> 窃取能力与打劫房屋的数目间存在单调性。

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        nums_ = nums;
        l = nums.size();

        sort(nums.begin(), nums.end());
        
        int i = 0, j = l - 1;
        while (i < j)
        {
            int m = (i + j) / 2;
            if (check(nums[m]) < k) i = m + 1;
            else j = m;
        } 

        return nums[i]; 
    }

    int check(int mx) {
        vector<int> f(l+2, 0);
        for (int i = 0; i < l; i++) {
            int n = nums_[i];
            f[i+2] = f[i+1];
            if (n <= mx)
                f[i+2] = max(f[i], f[i] + 1);
        }
        return f[l+1];
    }

private:
    vector<int> nums_;
    int l;
};