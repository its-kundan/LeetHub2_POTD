class Solution {
public:
    int findComplement(int num) {
        int ans =0;
        for(int i=0;num>0;i++){
            ans+= !(num%2)* pow(2,i);
            num/=2;
        }
        return ans;
        
        
    }
};