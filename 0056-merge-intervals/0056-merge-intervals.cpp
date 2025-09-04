class Solution {
public:
    static bool myCmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),myCmp);   

        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=s && intervals[i][0]<=e){
                s=min(s,intervals[i][0]);
                e=max(e,intervals[i][1]);
            }
            else{
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
        ans.push_back({s,e});
        return ans; 
    }
};