class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);  
        int i=1,n=intervals.size();
        int end=intervals[0][1];
        while(i<n){
            while(i<n && intervals[i][0]<end){
                ans++;
                i++;
            }
            if(i<n)end=intervals[i][1];
            i++;
        }
        return ans;
    }
};