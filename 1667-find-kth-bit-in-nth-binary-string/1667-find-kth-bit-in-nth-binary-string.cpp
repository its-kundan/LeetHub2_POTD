class Solution {
public:
    string inv(string s){
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                s[i]= '0';
            }else{
                s[i]= '1';
            }
        }
        reverse(s.begin(),s.end());
        return s;

    }
    string ok(string temp){
        string ans ="";
        ans+= temp;
        ans+= "1";
        ans+= inv(temp);
        return ans;

    }

    char findKthBit(int n, int k) {
        string temp = "0";
        while(n--){
            temp = ok(temp);
        }
        return temp[k-1];
        
    }
};