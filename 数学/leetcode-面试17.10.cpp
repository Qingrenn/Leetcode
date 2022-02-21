class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        // unordered_map<int, int> h;
        // for (auto n : nums) {
        //     h[n]++;
        //     if (h[n] > length / 2)  return n;
        // }
        // return -1;

        // 摩尔投票
        int x;
        int cnt = 0;
        for (auto n : nums) {
            if (cnt == 0) x = n;
            cnt += (n == x) ? 1 : -1;
        }
        cnt = 0;
        for (auto n : nums) if (n == x) cnt++;
        return (cnt > length / 2) ? x : -1;
    }
};
/*
摩尔投票的方法可以用o(1)的空间复杂度统计出众数。
*/