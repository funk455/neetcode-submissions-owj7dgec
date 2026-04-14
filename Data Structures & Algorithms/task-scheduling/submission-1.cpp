class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxheap;
        vector<int> count(26,0);
        for (auto & task : tasks) {
            count[task - 'A']++;
        }
        for ( int cnt : count) {
            if (cnt > 0) {
                maxheap.push(cnt);
            }
        }
        int time = 0;
        queue<pair<int,int>> q;
        while(!maxheap.empty() || !q.empty()) {
            time++;
            if (maxheap.empty()) {
                time = q.front().second;
            }else {
                int cnt = maxheap.top() - 1;
                maxheap.pop();
                if (cnt > 0) {
                    q.push({cnt,time+n});
                }
            }
            if (!q.empty() && time == q.front().second) {
                maxheap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
