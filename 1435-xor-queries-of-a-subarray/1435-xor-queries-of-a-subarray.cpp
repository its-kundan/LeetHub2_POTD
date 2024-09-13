class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        int m = q.size();
        int zor =0;
        vector<int> ans;
        for(int i=0;i<m;i++){
            int start = q[i][0];
            int end = q[i][1];
            zor =0;
            for(int j=start;j<=end;j++){
                zor^=arr[j];
            }
            ans.push_back(zor);
        }
        return ans;
        
    }
};