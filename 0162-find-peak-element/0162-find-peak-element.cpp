class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(n==2)return nums[0]>nums[1]?0:1;
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r){
            int mid= l + (r-l)/2;
            if( (mid==0 || nums[mid]>nums[mid-1]) && (mid==n-1 ||nums[mid]>nums[mid+1] )){
                return mid;
            }
            else if(mid>0 && nums[mid-1]>nums[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
        
    }
};