class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        vector<string> ans;
        int n = names.size();
        vector<pair<int,string>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({h[i],names[i]});
        }
        sort(temp.rbegin(),temp.rend());
        for(auto it: temp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};