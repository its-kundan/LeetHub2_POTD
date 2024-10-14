class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans =0;
        priority_queue<int> pq;
        int n = nums.size();
        for(auto it: nums){
            pq.push(it);
        }
        while(k--){
            int t = pq.top();
            pq.pop();
            ans+= t;
            pq.push(ceil(t/3.0));
            // pq.push((t/3)+(t%3!=0));
        }
        return ans;
        
    }
};