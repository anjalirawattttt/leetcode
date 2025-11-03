class Solution {
public:
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int result=1;
        for(int i=0;i<n;i++){
            unordered_map<string,int> m;
            int maxCount=1;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];
                int g=gcd(dy,dx);
                dy/=g;
                dx/=g;
                string temp=to_string(dy)+"_"+to_string(dx);
                m[temp]++;
                if(m[temp]+1>maxCount){
                    maxCount=m[temp]+1;
                }
            }
            result=max(result,maxCount);
        }
        return result;    
    }
};