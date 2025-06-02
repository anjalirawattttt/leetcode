class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum=0,rightSum=0;
        int i=0;
        int sum=0;

        for(int &n:nums)sum+=n;

        while(i<nums.size()){
            if(i>0)leftSum+=nums[i-1];
            rightSum=sum-leftSum-nums[i];    
            if(leftSum==rightSum)return i;   
            i++;     
        }  

        
        return -1; 
    }
};