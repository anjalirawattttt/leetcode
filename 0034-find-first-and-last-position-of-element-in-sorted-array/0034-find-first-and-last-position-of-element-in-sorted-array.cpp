class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid= l + (r-l)/2;
            if(nums[mid]==target){
                int i=mid;
                while(i>=0 && nums[i]==target){
                    ans[0]=i;
                    i--;    
                }
                i=mid;
                while(i<n && nums[i]==target){
                    ans[1]=i;
                    i++;    
                }
                break;
            }
            else if(nums[mid]<target) {
                l=mid+1;    
            }
            else{
                r=mid-1;
            }
        }
        return ans;    
    }
};