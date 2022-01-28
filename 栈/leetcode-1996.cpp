class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(),
            [=](const vector<int> &a, vector<int> &b) -> bool 
            { 
                if (a[0] == b[0])
                    return a[1] > b[1];
                else
                    return a[0] < b[0];
            });
        
        stack<int> s;
        int res = 0;
        for(vector<int> p : properties)
        {
            // cout << p[0] << " " <<  p[1]<< endl;
            while (!s.empty() && s.top() < p[1])  
            {
                // cout << s.top()[1] << " t" << endl;
                res++;
                s.pop();
            }
            s.push(p[1]);
        }

        // struct cmp
        // {
        //     bool operator()(const vector<int> &a, const vector<int> &b)
        //     {
        //         if (a[0] == b[0])
        //             return a[1] < b[1];
        //         return a[0] > b[0];
        //     }
        // };

        // priority_queue<vector<int>, vector<vector<int>>, cmp> heap;
        // for (vector<int> p : properties)
        //     heap.push(p);

        // stack<vector<int>> s;
        // int res = 0;
        // while (!heap.empty())
        // {
        //     vector<int> p = heap.top(); heap.pop();
        //     // cout << p[0] << " " <<  p[1]<< endl;
        //     if (s.empty() || s.top()[1] >= p[1])    s.push(p);
        //     else{
        //         while (!s.empty() && s.top()[1] < p[1])  
        //         {
        //             // cout << s.top()[1] << " t" << endl;
        //             res++;
        //             s.pop();
        //         }
        //         s.push(p);
        //     }
        // }
        
        return res;
    }
};

/*
在比较函数中，如果不是按引用传递，是深拷贝会超时！
*/