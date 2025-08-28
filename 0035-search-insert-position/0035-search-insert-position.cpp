class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int idx=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target){
                idx=mid;
                r=mid-1;
            }
            else{
                idx=mid+1;
                l=mid+1;
            }
        }  
        return idx;  
    }
};