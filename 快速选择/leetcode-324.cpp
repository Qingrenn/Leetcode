class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int bucket[500010] = {0};
        for (auto i : nums)
            bucket[i]++;
        
        int len = nums.size();
        int big, small;
        if (len & 1) {
            // 奇数 小 大 小 大 小
            big = len - 2;
            small = len - 1;
        } else {
            // 偶数 小 大 小 大
            big = len - 1;
            small = len - 2;
        }

        // 插入大值
        int j = 500009;
        for (int i = 1; i <= big; i += 2) {
            while (bucket[j] == 0) j--;
            bucket[j]--;
            nums[i] = j;
        }

        // 插入小值
        for (int i = 0; i <= small; i += 2) {
            while (bucket[j] == 0)  j--;
            bucket[j]--;
            nums[i] = j;
        }

        return;

    }
};

/*
由于数据大小不大，只有5e4。更优的方法应采用：快速选择 + 三分法
*/