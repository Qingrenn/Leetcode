class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size() - 1;
        int V = min(height[p1], height[p2]) * (p2 - p1);

        while (p1 != p2) {
            if (height[p1] <= height[p2]) {
                p1++;
            }else p2--;
            V = max(V, min(height[p1], height[p2]) * (p2 - p1));
        }

        return V;
    }
};

/*
重点在于：双指针的移动，实际上是在压缩解空间，而且是合理的。
不能以完全遍历的视角来看待。
*/