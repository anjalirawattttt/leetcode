class Solution {
public:
    int help(int i,vector<int> &nums,int target){
        if(i<0 && target==0)return 1;
        if(i<0)return 0;

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