class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (int i = 0; i < length; i++)
            m[nums[i]] = i;
        int backup_a=1e5+1, backup_b=1e5+1;
        for (int i = 0; i < length; i++)
        {
            int a = nums[i];
            if (a > 0)  break;
            if (a == backup_a)  continue;
            backup_a = a;
            
            for (int j = i + 1; j < length; j++)
            {
                int b = nums[j];
                if (b == backup_b)  continue;
                backup_b = b;
                int c = - (a + b);
                if ( m[c] > j )
                {
                    vector<int> tmp = {a, b, c};
                    res.push_back(tmp);
                }
            }
        }

        return res;
    }
};

/*
用hash写要特别注意如何去重复！！！
双指针才是最优解
*/