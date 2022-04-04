class NumArray {
private:
    vector<int> N;
    vector<int> C;

    int lowbit(int x) {
        return x & -x;
    }

    int prefix(int q) {
        // calculate prefix in binary tree array
        int ans= 0;
        for (int i = q + 1; i >= 1; i -= lowbit(i))
            ans += C[i];
        return ans;
    }

public:
    NumArray(vector<int>& nums):N(nums) {
        // create binary tree array
        C = vector<int>(N.size() + 1, 0);
        for (int i = 1; i < C.size(); i++) {
            C[i] += N[i-1];
            if (i + lowbit(i) < C.size())  C[i + lowbit(i)] += C[i];
        }
    }
    
    void update(int index, int val) {
        // update binary tree array
        int d = val - N[index];
        for (int i = index + 1; i < C.size(); i += lowbit(i))
            C[i] += d;
         N[index] = val;
    }
    
    int sumRange(int left, int right) {
        return prefix(right) - prefix(left) + N[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/**
 * 
 * 各类区间和问题如何解决 
 * https://leetcode-cn.com/problems/range-sum-query-mutable/solution/guan-yu-ge-lei-qu-jian-he-wen-ti-ru-he-x-41hv/
 * 
 * 数组不变，求区间和：「前缀和」、「树状数组」、「线段树」
 * 多次修改某个数（单点），求区间和：「树状数组」、「线段树」
 * 多次修改某个区间，输出最终结果：「差分」
 * 多次修改某个区间，求区间和：「线段树」、「树状数组」（看修改区间范围大小）
 * 多次将某个区间变成同一个数，求区间和：「线段树」、「树状数组」（看修改区间范围大小）
 * 
 * 
 * 
 */