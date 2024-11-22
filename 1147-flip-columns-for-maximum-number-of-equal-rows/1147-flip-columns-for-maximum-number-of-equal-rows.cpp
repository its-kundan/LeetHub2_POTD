class Solution {
public:
    void helper(vector<int>&v1)
    {
        for(int i=0; i<v1.size(); i++)
        {
            v1[i]=~v1[i]+2;
        }
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>, int>mymap;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0; i<m; i++)
        {
            vector<int>v1=matrix[i];
           
            mymap[v1]++;
            helper(v1);
            mymap[v1]++;
        }
        int ans=0;
        for(auto i=mymap.begin(); i!=mymap.end(); i++)
        {
            ans=max(ans, i->second);
        }
        return ans;
        
    }
};