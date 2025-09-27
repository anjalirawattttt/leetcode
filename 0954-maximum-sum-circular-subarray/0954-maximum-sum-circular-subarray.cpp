class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int sum=nums[0];
        int totalSum=nums[0];
        for(int i=1;i<n;i++){
            totalSum+=nums[i];
            sum=max(sum+nums[i],nums[i]);
            maxSum=max(maxSum,sum);
        }
        if(maxSum<0)return maxSum;
        sum=nums[0];
        int minSum=nums[0];
        for(int i=1;i<n;i++){
            sum=min(sum+nums[i],nums[i]);
            minSum=min(minSum,sum);
        }
        maxSum=max(maxSum,totalSum-minSum);

        return maxSum;    
    }
};