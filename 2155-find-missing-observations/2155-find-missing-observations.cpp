class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean*(m+n);
        int roll=0,remain=0;
        for(auto it:rolls){
            roll+=it;
        }
        remain = sum-roll;
        vector<int> ans;
        if(remain> n*6 || remain<n){
            return ans;
        }
        int rmean = remain/n, r= remain%n;

        for(int i=0;i<n-r;i++){
            ans.push_back(rmean);
        }
        for(int i=0;i<r;i++){
            ans.push_back(rmean+1);
        }
        return ans;
        
    }
};