class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // for (auto it = nums.begin(); it != nums.end(); ) {
        //     if ( *it == val )   nums.erase(it);
        //     else it++;
        // }
        // return nums.size();
        
        // return remove(nums.begin(), nums.end(), val) - nums.begin(); 
        
        int l = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            if (nums[r] != val) {
                nums[l] = nums[r];
                l++; 
            }
        }
        return l;

    }
};