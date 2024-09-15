class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> countMap;
        vector<int> result;
        for (int num : nums) {
            if (++countMap[num] == 2) {
                result.push_back(num);
                if (result.size() == 2) {
                    break;
                }
            }
        }
        return result;
    }
};