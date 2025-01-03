class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long total_sum = 0;
        for (int num : nums) {
            total_sum += num;  // Calculate total sum of the array
        }
        
        long left_sum = 0;
        int count = 0;
        
        for (int i = 0; i < n - 1; ++i) {  // We need at least one element in the right part
            left_sum += nums[i];
            if (left_sum >= total_sum - left_sum) {
                count++;
            }
        }
        
        return count;
    }
};