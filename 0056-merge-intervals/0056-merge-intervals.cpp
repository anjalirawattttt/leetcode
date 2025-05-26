class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        int n=intervals.size();
        if(n<=1)return intervals;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            if(a[0]==b[0])return a[1]<b[1];
            else return a[0]<b[0];
        });

        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
            else{
                v.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        v.push_back({start,end});
        return v;
    }
};