class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> falseIndex;
        
        for(int i = 1; i < n; i++)
            if(nums[i] % 2 == nums[i-1] % 2)
                falseIndex.push_back(i);
        
        int size = falseIndex.size();
        vector<bool> ans(q.size(), true);
        
        if(size == 0) return ans;
        
        for(int i = 0; i < q.size(); i++) {
            if(q[i][1] == q[i][0]) continue;
            
            int lower = lower_bound(falseIndex.begin(), falseIndex.end(), q[i][0] + 1) - falseIndex.begin();
            if(lower < size && falseIndex[lower] <= q[i][1])  ans[i] = false;
        }
        return ans;
    }
};