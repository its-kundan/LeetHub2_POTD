class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<int> ans, rmin,cmax;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=0;j<m;j++){
                mini = min(mini,matrix[i][j]);
            }
            rmin.push_back(mini);
        }


        for(int j=0;j<m;j++){
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                maxi = max(maxi,matrix[i][j]);
            }
            cmax.push_back(maxi);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rmin[i]==cmax[j]){
                    ans.push_back(rmin[i]);
                }
            }
        }
        return ans;
        
    }
};