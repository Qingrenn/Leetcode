class Solution {
public:
    int findTheWinner(int n, int k) {
        // vector<int> ne(n+1);
        // for (int i = 1; i < n; i++) ne[i] = i + 1;
        // ne[n] = 1;
        // int num = n;
        
        // if (k==1)
        //     return n;
        // int i = 1;
        // while (num > 1) {
        //     for (int j = 0; j < k - 2; j++)
        //         i = ne[i];
        //     int cur_next = ne[i];
        //     ne[i] = ne[cur_next];
        //     ne[cur_next] = -1;
        //     num--;
        //     i = ne[i];
        // }
        // return i;
        if (n <= 1) return 1;
        int ans = (findTheWinner(n-1, k) + k - 1) % n + 1;
        return ans;
    }
};