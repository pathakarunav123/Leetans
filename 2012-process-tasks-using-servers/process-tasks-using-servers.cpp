class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free;
        
        // {free time, {weight, index}}
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> busy;

        // initially, all servers are free
        for (int i = 0; i < servers.size(); i++) free.push({servers[i], i});

        vector<int> ans(tasks.size());

        long long time = 0;
        for (int j = 0; j < tasks.size(); j++) {
            time = max(time, (long long) j); // task j arrives at time j

            // move finished servers to free
            while (!busy.empty() && busy.top().first <= time) {
                auto curr = busy.top();
                busy.pop();
                free.push(curr.second);
            }

            // no free server, increase time
            if (free.empty()) {
                time = busy.top().first;

                // move finished servers to free at this time
                while (!busy.empty() && busy.top().first <= time) {
                    auto curr = busy.top();
                    busy.pop();
                    free.push(curr.second);
                }
            }

            // best free server
            auto [weight, index] = free.top();
            free.pop();
            ans[j] = index;

            // server busy until this task finishes
            busy.push({time + tasks[j], {weight, index}});
        }

        return ans;
    }
};