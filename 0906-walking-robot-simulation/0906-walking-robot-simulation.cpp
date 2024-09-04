class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        set<pair<int,int>>m;
        int x=0,y=0,d=1;
        int ans=0;
        int direc[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<obs.size();i++){
            m.insert({obs[i][0],obs[i][1]});
        }
        for(int i=0;i<com.size();i++){
            if(com[i]==-1)d=(d+1)%4;
            else if(com[i]==-2){
                d--;
                if(d<0)d=3;
            }
            else{
                for(int j=0;j<com[i];j++){
                    if(m.find({x+direc[d][0],y+direc[d][1]})!=m.end()){
                        break;
                    }
                    else x+=direc[d][0],y+=direc[d][1];
                    ans=max(ans,x*x+y*y);
                }
            }
            
        }
        return ans;
    }
};