class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n=a.size();
        int maxe = *max_element(a.begin(),a.end());
        
        int len=0;
        int maxlen=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==maxe){
                len++;
            }else{
                len=0;
            }
			maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};