class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=1,n=intervals.size(),remove=0;
        int start=intervals[0][0],end=intervals[0][1];
        while(i<n){
            if(intervals[i][0]<end){
                remove++;
                if(intervals[i][1]<end && intervals[i][0]>=start){
                    start=intervals[i][0];
                    end=intervals[i][1];
                }
            }
            else{
                start=intervals[i][0];
                end=intervals[i][1];
            }
            i++;
        }
        return remove;   
    }
};