class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> newIntervals;
        int i=1,n=intervals.size();
        int start=intervals[0][0],end=intervals[0][1];
        while(i<n){
            if(intervals[i][0]<=end){
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
            else{
                newIntervals.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            i++;
        }
        newIntervals.push_back({start,end});
        return newIntervals;    
    }
};