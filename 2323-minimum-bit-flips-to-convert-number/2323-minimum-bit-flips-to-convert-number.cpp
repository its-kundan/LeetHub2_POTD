class Solution {
public:
    int minBitFlips(int start, int goal) {
        int zor = start^goal;
        return __builtin_popcount(zor);
        
    }
};