class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        int n=intervals.size();
        int i=0;
        
        while(i<n && newInterval[0]>intervals[i][1]){
            newIntervals.push_back(intervals[i]);
            i++;
        }

        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        newIntervals.push_back(newInterval);

        while(i<n){
            newIntervals.push_back(intervals[i]);
            i++;
        }



        return newIntervals;
    }
};