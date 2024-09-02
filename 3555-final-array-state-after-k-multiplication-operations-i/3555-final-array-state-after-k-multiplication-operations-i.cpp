#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            int minIndex = distance(nums.begin(), min_element(nums.begin(), nums.end()));
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};
