class Solution {
public:
    static bool myCmp(const vector<int>&a,const vector<int>&b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(),points.end(),myCmp);
        int start=points[0][0],end=points[0][1];
        int i=1,n=points.size();
        while(i<n){
            if(points[i][0]>=start && points[i][0]<=end){
                start=max(start,points[i][0]);
                end=min(end,points[i][1]);
            }
            else{
                ans++;
                start=points[i][0];
                end=points[i][1];
            }
            i++;
        }
        ans++;
        return ans;
    }
};