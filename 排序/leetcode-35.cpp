class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (target > nums[r])   return r + 1;
        if (target < nums[l])   return l;
        while (l < r)
        {
            int m = l + r >> 1;
            if (nums[m] >= target)  r = m;
            else l = m + 1;
        }
        return l;

    }
};

/*
二分查找要主要搜索目标以及，取m的时候是取向上取整还是向下取整。
这个可以根据仅有两个元素时如何退出进行判断。
*/