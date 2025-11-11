class Solution {
public:
    static bool myCmp(const vector<int>&a,const vector<int> &b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),myCmp);
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