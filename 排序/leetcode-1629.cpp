/*
直接比较
*/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        pair<int, char> res;

        res = {releaseTimes[0], keysPressed[0]};
        int back_up = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); i++) {
            int cur_last_time = releaseTimes[i] - back_up;
            if (cur_last_time > res.first)
                res = {cur_last_time, keysPressed[i]};
            else if (cur_last_time == res.first) 
                res.second = max(res.second, keysPressed[i]);
            back_up = releaseTimes[i];
        }

        return res.second;
    }
};


/*
堆排序
*/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        typedef pair<int, char> PIC;

        struct cmp
        {
            bool operator()(const PIC &a, const PIC &b)
            {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            }
        };

        priority_queue<PIC, vector<PIC>, cmp> heap;

        int backup = 0;
        for (int i = 0; i < keysPressed.size(); i++) {
            heap.push({releaseTimes[i] - backup, keysPressed[i]});
            backup = releaseTimes[i];
        }

        return heap.top().second;
    }
};
