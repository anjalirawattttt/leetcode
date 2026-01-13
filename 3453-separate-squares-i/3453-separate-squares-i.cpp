class Solution {
public:
    bool check(double limit_y,vector<vector<int>>& squares,double &totalArea){
        double area=0;
        for(auto &sq:squares){
            int y=sq[1];
            int l=sq[2];
            if(y<limit_y){
                area+=(double)l*(min(limit_y-y,(double)l));
            }
        }
        return area>=(totalArea/2);
    }

    double separateSquares(vector<vector<int>>& squares) {      
        double totalArea=0;
        int n=squares.size();
        double maxY=INT_MIN;
        for(int i=0;i<n;i++){
            int x=squares[i][0];
            int y=squares[i][1];
            int l=squares[i][2];
            maxY=max(maxY,(double)y+l);
            totalArea+=(double)l*l;
        }

        double l=0,h=maxY;
        double eps=1e-5;
        while((h-l)>eps){
            double mid = l + (h-l)/2;
            if(check(mid,squares,totalArea)){
                h=mid;
            }
            else{
                l=mid;
            }
        }
        return h;        
    }
};