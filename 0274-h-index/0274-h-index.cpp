class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if(n==1)return citations[0]==0?0:1;
        sort(citations.begin(),citations.end());
        int ans=0;
        int l=0,r=n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(n-1-mid+1<=citations[mid]){
                ans=n-1-mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;                
            }
        }
        return ans;   
    }
};