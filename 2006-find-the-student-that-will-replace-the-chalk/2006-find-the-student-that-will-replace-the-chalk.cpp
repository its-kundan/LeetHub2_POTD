class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0; // Use long long to avoid overflow
        for(int i = 0; i < n; i++){
            sum += chalk[i];
        }
        k = k % sum; // Modulo operation remains the same
        for(int i = 0; i < n; i++){
            k -= chalk[i];
            if(k < 0) return i;
        }
        return -1;
    }
};
