class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double ans=0;
        for(int i=0;i<n-2;i++){
            long long x1=points[i][0],y1=points[i][1];
            for(int j=i+1;j<n-1;j++){
                long long x2=points[j][0],y2=points[j][1];
                for(int k=j+1;k<n;k++){
                    long long x3=points[k][0],y3=points[k][1];
                    double cross = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
                    cross=llabs(cross);
                    ans=max(ans,0.5*cross);
                }
            }
        }
        return ans;
    }
};