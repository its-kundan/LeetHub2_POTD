class Solution {
public:
    double distance(vector<int>& p1, vector<int>& p2){
        double d1=abs(p1[0]-p2[0]);
        double d2=abs(p1[1]-p2[1]);
        d1*=d1;
        d2*=d2;
        return sqrt(d1+d2);
    }
    double area(double a, double b, double c){
        double s=(a+b+c)/2.0;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=0.0;
        double a=0,b=0,c=0;
        int n=points.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                a=distance(points[i],points[j]);
                for(int k=j+1;k<n;k++){
                    b=distance(points[j],points[k]);
                    c=distance(points[i],points[k]);
                    ans=max(ans,area(a,b,c));
                }
            }
        }
        return ans;
    }
};