class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();  
        int maxLength=0; 
        int count=0;
        while(r<n){
            if(nums[r]==0){
                count++;       
            } 
            while(count>k && l<n){
                if(nums[l]==0)count--;
                l++;
            }

            int length=r-l+1;
            maxLength=max(maxLength,length);
            r++;   
        } 
        return maxLength;
    }
};