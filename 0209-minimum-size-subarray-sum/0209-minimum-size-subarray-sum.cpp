class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=INT_MAX,sum=0;
        int l=0,r=0;
        int n=nums.size();
        while(r<n){
            sum+=nums[r];
            while(l<=r && sum>=target){
                minLen=min(minLen,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return minLen==INT_MAX?0:minLen;    
    }
};