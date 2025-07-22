class Solution {
public:
    int help(int i,vector<int>& nums, int target){
        if(i==0){
            if(nums[0]==0 && nums[0]==abs(target))return 2;
            if(nums[0]==abs(target))return 1;
            return 0;
        }
        //+
        int op1=help(i-1,nums,target-nums[i]);
        //-
        int op2=help(i-1,nums,target+nums[i]);
        return op1+op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return help(n-1,nums,target);
    }
};