class Solution {
    int dis(vector<int> a, vector<int> b){
        int x = a[0];
        int y = a[1];
        int x1 = b[0];
        int y1= b[1];
        int ans = (x-x1)*(x-x1) + (y-y1)*(y-y1);
        if(!ans) return -1;
        return ans;

    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int,int> mp;
        int s1 = dis(p1,p2),s2=dis(p1,p3),s3=dis(p1,p4);
        int s4 = dis(p2,p3), s5 = dis(p2,p4);
        int s6 = dis(p3,p4);
        mp[s1]++;
        mp[s2]++;
        mp[s3]++;
        mp[s4]++;
        mp[s5]++;
        mp[s6]++;
        if(mp.size()!=2) return false;
        vector<int> x;
        for(auto it: mp){
            x.push_back(it.second);
            if(it.first==-1){
                return false;
            }

        }
        sort(x.begin(),x.end());
        if(x[0]==2 && x[1]==4) return true;
        return false;

        
    }
};