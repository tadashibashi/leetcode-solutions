class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0;
        priority_queue<int> q;

        for (const int &n : stones)
            q.push(n);
        
        while (q.size() > 1) {
            int first = q.top(); q.pop();
            int second = q.top(); q.pop();

            if (first != second)
                q.push(first - second);
        }

        return q.empty() ? 0 : q.top();
    }
};