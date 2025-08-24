class Solution {
public:
    static bool myCmp(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),myCmp);    
        int ans=0;
        int l=intervals[0][0],r=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=r){
                l=intervals[i][0];   
                r=intervals[i][1]; 
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};