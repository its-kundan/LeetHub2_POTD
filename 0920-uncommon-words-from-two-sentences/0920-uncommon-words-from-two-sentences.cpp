class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        int n = s1.size();
        int m = s2.size();
        unordered_map<string,int> temp;
        string str="";
        for(int i=0;i<n;i++){
            if(s1[i]==' '){
                temp[str]++;
                str="";
            }else{
                str+= s1[i];
                if(i==n-1){
                    temp[str]++;
                    str="";
                }
            }

        }
        for(int i=0;i<m;i++){
            if(s2[i]==' '){
                temp[str]++;
                str="";
            }else{
                str+= s2[i];
                 if(i==m-1){
                    temp[str]++;
                    str="";
                }
            }

        }
        for(auto it: temp){
            if(it.second ==1){
                ans.push_back(it.first);
            }
        }
        return ans;

        
    }
};