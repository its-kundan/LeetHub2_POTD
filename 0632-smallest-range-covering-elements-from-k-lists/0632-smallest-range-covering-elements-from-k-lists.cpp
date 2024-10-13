class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        int maxi=nums[0][0];
        for(int i=0;i<k;i++){
            maxi=max(maxi,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }

        int f=1;
        int fmin=pq.top().first;
        int fmax=maxi;
        int ans=fmax-fmin+1;

        while(f){
            auto it=pq.top();
            pq.pop();
            if(it.second.second == nums[it.second.first].size()-1){
                f=0;
            }else{
                maxi=max(maxi,nums[it.second.first][it.second.second+1]);
                pq.push({nums[it.second.first][it.second.second+1],{it.second.first,it.second.second+1}});
                int mini=pq.top().first;
                if(ans > (maxi-mini+1)){
                    ans=(maxi-mini+1);
                    fmin=mini;
                    fmax=maxi;
                }
            }
        }

        vector<int> res;
        res.push_back(fmin);
        res.push_back(fmax);

        return res;
    }
};