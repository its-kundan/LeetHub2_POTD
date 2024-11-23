class Solution {
private:
    // apply gravity row-wise
    void solve(vector<char>& s){
        int l=s.size()-1, r=s.size()-1;
        while(l>=0){
            if(s[l]=='.'){
                l--;
            }
            else if(s[l]=='#'){
                if(s[r]=='.'){
                    swap(s[r], s[l]);
                }
                r--;
                l--;
            }
            else if(s[l]=='*'){
                l--;
                r=l;
            }            
        }
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(int row=0;row<box.size();row++){
            solve(box[row]);
        }

        // rotate the data
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                ans[col][m - row - 1] = box[row][col];
            }
        }

        return ans;
    }
};