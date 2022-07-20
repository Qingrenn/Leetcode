class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = accumulate(numsDivide.begin(), numsDivide.end(), numsDivide[0], gcd);
        // printf("%d", g);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (g % nums[i] == 0) return i;
        }
        return -1;
    }

    static int gcd (int a, int b) {
        if (b == 0) return a;
        return gcd (b, a % b);
    }

};