class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string word : words)
            m[word]++;
        
        struct SI {
            string word;
            int num;
            bool operator<(const SI &si) const{
                if (num != si.num)
                    if (num < si.num)   return true;
                    else return false;
                else
                    return word > si.word;
            }
        };
        priority_queue<SI, vector<SI>, less<SI>> h;
        for (auto p : m) {
            SI si = {p.first, p.second};
            h.push(si);
        }
            
        vector<string> res;
        while (k--) {
            res.push_back(h.top().word);
            h.pop();
        }
        return res;
    }
};

/*
hashmap统计频率 + priority_queue排序
*/