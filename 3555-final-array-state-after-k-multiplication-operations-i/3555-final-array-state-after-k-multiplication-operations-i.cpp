#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            // Find the index of the first minimum value in the array
            int minIndex = distance(nums.begin(), min_element(nums.begin(), nums.end()));
            // Multiply the element at minIndex by the multiplier
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};
