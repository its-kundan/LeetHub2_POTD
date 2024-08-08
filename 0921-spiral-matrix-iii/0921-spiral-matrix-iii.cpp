class Solution {
public:
    bool isvalid(int i,int j, int row, int col)
    {
        return (i>=0 && j>=0 && i<row && j<col);
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart,cStart});

        int step = 1;
        int i = rStart,j = cStart;

        while(ans.size() < rows*cols)
        {
            if(ans.size()==rows*cols)
            return ans;

            int k=0;
            while(k<step)
            {
                j++;
                if(isvalid(i,j,rows,cols))
                {
                    ans.push_back({i,j});
                    if(ans.size()==rows*cols)
                    return ans;
                }
                k++;
            }

            k=0;
            while(k<step)
            {
                i++;
                if(isvalid(i,j,rows,cols))
                {
                    ans.push_back({i,j});
                    if(ans.size()==rows*cols)
                    return ans;
                }
                k++;
            }

            step++;

            k=0;
            while(k<step)
            {
                j--;
                if(isvalid(i,j,rows,cols))
                {
                    ans.push_back({i,j});
                    if(ans.size()==rows*cols)
                    return ans;
                }
                k++;
            }

            k=0;
            while(k<step)
            {
                i--;
                if(isvalid(i,j,rows,cols))
                {
                    ans.push_back({i,j});
                    if(ans.size()==rows*cols)
                    return ans;
                }
                k++;
            }

            step++;

        }
        return ans;
    }
};