class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int result=1;
        for(int i=0;i<n;i++){
            unordered_map<double,int> m;
            int maxCount=1;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];
                double theta=atan2(dy,dx);
                m[theta]++;
                if(m[theta]+1>maxCount){
                    maxCount=m[theta]+1;
                }
            }
            result=max(result,maxCount);
        }
        return result;    
    }
};