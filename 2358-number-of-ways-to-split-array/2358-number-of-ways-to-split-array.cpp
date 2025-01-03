class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sum = 0;
        int n = nums.size();
        for(auto it: nums){
            sum+= it;
        }
        long sum2=0;
        int ans =0;
        for(int i=0;i<n-1;i++){
            sum2+= nums[i];
            if(sum2>= sum-sum2) ans++;
            

        }
        return ans;
        
    }
};