class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int length = arr.size();
        if (length < 3) return 0;
        arr.push_back(10001);
        arr.insert(arr.begin(), 10001);
        
        int l = 0, res = 0;
        for (int i = 1; i <= length; i++) {
            if ( !(arr[i-1] < arr[i]) && !(arr[i+1] < arr[i]) && !(arr[i-1] == arr[i] && arr[i] == arr[i+1]  )){
                if ( l == 0)   l = i;
                else {
                    res = max(i - l + 1, res);
                    l = i;
                }
            }
            if (arr[i] == arr[i+1]) l = 0;
            
        }
        return res;
    }
};

/*
通过找极小值来确定来确定，两个相邻极小值之间的距离，但是会遇到鞍点，要特殊处理。
*/