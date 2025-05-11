class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        sort(nums.begin(),nums.end());
        int r=nums.size()-1;
        int count=1;
        while(count!=k){
            r--;
            count++;
        
        }
        ans=nums[r];
        return ans;
    }
};