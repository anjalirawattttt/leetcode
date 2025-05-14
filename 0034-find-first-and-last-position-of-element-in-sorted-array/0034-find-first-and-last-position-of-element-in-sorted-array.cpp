class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v={-1,-1};
        int l=0;
        int r=nums.size()-1;
        int mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]==target){
                int i=mid+1;
                while(i<nums.size() && nums[i]==nums[i-1]){
                    i++;
                }
                v[1]=i-1;

                i=mid-1;
                while(i>=0 && nums[i]==nums[i+1] ){
                    i--;
                }
                v[0]=i+1;
                break;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            
        }
        return v;
    }
};