class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        typedef long long LL;
        int k = k1 + k2;
        vector<int> diff(nums1.size());
        LL ans = 0, sum = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff[i] = d;
            ans += (LL) d * d;
            sum += d;
        }
        if (sum <= k)
            return 0;
        sort(diff.begin(), diff.end(), greater<int>());
        diff.push_back(0);
        for (int i = 0; i < diff.size(); i++) {
            int j = i + 1, v = diff[i], c = j * (v - diff[j]);
            ans -= (LL) v * v;
            if (c < k) {
                k -= c;
                continue;
            }
            v  -= k / j;
            return ans + (LL) k%j * (v-1) * (v-1) + (LL) (j-k%j) * v * v;
        }
        return 0;

            
    }
};