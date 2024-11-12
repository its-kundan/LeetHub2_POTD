class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& v1, vector<int>& v) {
        int n = v.size(),i;
        vector<vector<int>> v2;
        for(i=0;i<n;i++){
            v2.push_back({v[i],i});
        }
        vector<int> ans(n,0);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int  j = 0, x = 0, a = v1.size(),b=v2.size();
        i = 0;
        while(j<b){
            while(i<a&&v2[j][0]>=v1[i][0]){
                x = max(v1[i][1],x);
                i++;
            }
            ans[v2[j][1]] = x;
            j++;
        }
        return ans;
    }
};