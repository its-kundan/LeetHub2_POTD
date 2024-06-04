class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        // int oddMax =0,ans=0;
        for(auto it: s){
            mp[it]++;
        }
        int count =0;
        bool hasOddFreq = false;

        for(auto it: mp){
            count+= (it.second/2)*2;
            if(it.second%2) hasOddFreq=true;
        }
        
        return hasOddFreq?count+1: count;
        
    }
};