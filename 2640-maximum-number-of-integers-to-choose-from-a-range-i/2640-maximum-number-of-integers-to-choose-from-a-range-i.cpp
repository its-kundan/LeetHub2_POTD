class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end()); // Use a set for fast lookup
        int ct = 0;
        int currSum = 0;

        for (int i = 1; i <= n; i++) {
            if (bannedSet.find(i) == bannedSet.end()) { // Only consider non-banned elements
                if (currSum + i > maxSum) {
                    return ct; // Stop if the sum exceeds maxSum
                }
                currSum += i;
                ct++;
            }
        }
        return ct;
    }
};
