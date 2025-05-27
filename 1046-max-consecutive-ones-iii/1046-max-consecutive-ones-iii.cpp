class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int maxLength=0;
        int n=nums.size();
        int count=0;

        while(r<n){
            if(nums[r]==0){
                count++;
            }

            if(count>k){
                if(nums[l]==0)count--;
                l++;
            }

            if(count<=k){
                int length=r-l+1;
                maxLength=max(maxLength,length);
            }
            
            r++;

        }
        return maxLength;
    }
};