class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx=-1;
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]==target){
                idx=mid;
                break;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return idx;
    }
};