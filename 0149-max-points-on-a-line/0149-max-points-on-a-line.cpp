class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int result=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double slope=(double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                int count=2;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j){
                        double slope2=(double)(points[k][1]-points[i][1])/(points[k][0]-points[i][0]);
                        if(slope==slope2)count++;
                    }
                }
                result=max(result,count);
            }
        }
        return result;    
    }
};