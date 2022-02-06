class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        // int res = 0;
        // unordered_map<int, int> m;
        // for (int n : nums)
        // {
        //     m[n]++;
        //     if (m[n] == 1)  res += n;
        //     else if (m[n] == 2)  res -= n;
        // }

        // return res;

        int res = 0;
        int bucket[101] = {0};
        for (int n : nums)
        {
            bucket[n]++;
            if (bucket[n] == 1) res += n;
            else if (bucket[n] == 2) res -= n;
        }
        return res;
    }
};