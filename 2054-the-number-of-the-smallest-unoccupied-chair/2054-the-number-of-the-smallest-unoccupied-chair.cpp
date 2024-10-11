class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int n = times.size();
        vector<tuple<int, int, int>> events; // time flag(1->arrival) idx
        for (int i = 0; i < n; i++) {
            events.push_back(make_tuple(times[i][0], 1, i));
            events.push_back(make_tuple(times[i][1], 0, i));
        }

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> avCh;
        for (int i = 0; i < n; i++)
            avCh.push(i);

        vector<int> guCh(n, -1);

        for (auto& event : events) {
            int time = get<0>(event);
            int flag = get<1>(event);
            int idx = get<2>(event);

            if (flag == 1) {
                int chair = avCh.top();
                avCh.pop();
                guCh[idx] = chair;

                if (idx == targetFriend)
                    return chair;
            } else
                avCh.push(guCh[idx]);
        }
        return -1;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();