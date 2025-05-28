class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        int count=0,maxLength=0;
        while(r<n){
            if(nums[r]==0)count++;
            if(count>k){
                if(nums[l]==0)count--;
                l++;
            }
            if(count<=k){
                maxLength=max(maxLength,r-l+1);
            }
            r++;
        } 
        return maxLength;   
    }
};