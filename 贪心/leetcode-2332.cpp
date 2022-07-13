class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        // 贪心：找到最后一个能上车的，从后往前插队
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int j = 0, c;
        for (int i = 0; i < buses.size(); i++) {
            c = capacity;
            while (c > 0 && j < passengers.size() && passengers[j] <= buses[i]) {
                c--;
                j++;
            }
        }
        j -= 1;
        int ans = c ? buses.back() : passengers[j];
        while (j >= 0 && ans == passengers[j]) {
            ans--;
            j--;
        }
        return ans;


    }
};