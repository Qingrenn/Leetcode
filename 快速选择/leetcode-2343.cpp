class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> indexs(nums.size());
        for (int i = 0; i < nums.size(); i++) 
            indexs[i] = i;

        int l = nums[0].length();
        map<int, vector<int>> m;
        for (auto q : queries) {
            int tr = q[1];
            if (m.count(tr))  continue;
            vector<int> tmp = indexs;
            sort(tmp.begin(), tmp.end(), [&] (int a, int b) -> bool {
                for (int i = l - tr; i < l; i++) {
                    if (nums[a][i] > nums[b][i])    return false;
                    if (nums[a][i] < nums[b][i])    return true;
                }
                return a < b;
            });
            m[tr] = tmp;
        }

        vector<int> res;
        for (auto q : queries) {
            int k = q[0], tr = q[1];
            res.push_back(m[tr][k-1]);
        }
        return res;

    }
};