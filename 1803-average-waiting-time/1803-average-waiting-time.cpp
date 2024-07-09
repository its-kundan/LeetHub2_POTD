class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = 0;
        int curr = 0;

        for(auto& customer : customers)
        {
            int arrival = customer[0];
            int service = customer[1];
            if(curr < arrival)
            {
                curr = arrival;
            }
            int wait = curr - arrival + service;
            total = total + wait;
            curr = curr + service;
        }
        int n = customers.size();
        double ans = total / n;
        return ans;
    }
};