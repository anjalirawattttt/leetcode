class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)return 0;
        int ans=0;
        int x=points[0][0],y=points[0][1];
        for(int i=1;i<n;i++){
            int minEle=min(abs(points[i][0]-x),abs(points[i][1]-y));
            int remaining=max(abs(points[i][0]-x),abs(points[i][1]-y))-minEle;
            int temp=minEle+remaining;
            x=points[i][0];
            y=points[i][1];
            ans+=temp;
        } 
        return ans;   
    }
};