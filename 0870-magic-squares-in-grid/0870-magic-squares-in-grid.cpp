class Solution {
public:
    bool valid(vector<vector<int>>& grid, int x, int y) {
        int sum = grid[x][y] + grid[x][y+1] + grid[x][y+2];

        // Unique number check
        vector<int> count(10, 0);
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || count[grid[i][j]] > 0) return false;
                count[grid[i][j]]++;
            }
        }

        // Row check
        for (int i = x; i < x + 3; ++i) {
            int rowSum = 0;
            for (int j = y; j < y + 3; ++j) {
                rowSum += grid[i][j];
            }
            if (rowSum != sum) return false;
        }

        // Column check
        for (int j = y; j < y + 3; ++j) {
            int colSum = 0;
            for (int i = x; i < x + 3; ++i) {
                colSum += grid[i][j];
            }
            if (colSum != sum) return false;
        }

        // Diagonal check
        int diaSum1 = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        if (diaSum1 != sum) return false;
        int diaSum2 = grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2];
        if (diaSum2 != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n < 3 || m < 3) return 0;

        int count = 0;
        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= m - 3; ++j) {
                if (grid[i+1][j+1] != 5) continue; // Middle value of a 3x3 magic square 1-9 is always 5
                if (valid(grid, i, j)) {
                    ++count;
                }
            }
        }
        return count;
    }
};
