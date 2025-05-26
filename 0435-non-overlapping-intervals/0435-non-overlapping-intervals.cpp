class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
        });
        
        int start=intervals[0][0],end=intervals[0][1],count=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                count++;
                end=min(end,intervals[i][1]);
            }
            else{
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }

        return count;
    }
};