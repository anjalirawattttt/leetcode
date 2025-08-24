class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }

        int x=newInterval[0];
        int y=newInterval[1];

        int i=0;

        while(i<n && intervals[i][1]<x){
            ans.push_back(intervals[i]);
            i++;
        }

        
        while( i<n && intervals[i][0]<=y ){
            x=min(x,intervals[i][0]);
            y=max(y,intervals[i][1]);
            i++;
        }
        ans.push_back({x,y});

        while(i<n){
            ans.push_back(intervals[i]);
            i++;    
        }



        return ans;     
    }
};