class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int x = quick_select(nums, 0, nums.size() - 1, nums.size() / 2);
        int res = 0;
        for (int n : nums) 
            res += abs(n - x);
        return res;
        
    }

    int quick_select(vector<int>& nums, int left, int right, int k){
        int index = randomPartion(nums, left, right);
        if (index == k) return nums[index];
        else return k > index ? quick_select(nums, index+1, right, k) : quick_select(nums, left, index-1, k);
    }

    int randomPartion(vector<int> &nums, int left, int right) {
        int ri = rand() % ( right - left + 1) + left;
        swap(nums[ri], nums[right]);
        int i = left - 1, x = nums[right];
        for (int j = left; j < right; j++) {
            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
};

/**
 * @brief 
 * 快排在每次处理完一个区间后，做比较的那个数的位置实际上就已经确定下来了。
 * 所以根据每次确定的数位置，来对其左区间或者有区间做快排，直到我们想要的第k个数的位置被确定。
 * o(ns)
 * 
 */