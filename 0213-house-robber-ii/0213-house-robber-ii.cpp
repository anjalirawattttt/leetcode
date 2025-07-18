class Solution {
public:
    int help(vector<int>& nums){
       int n=nums.size();
       int prev=nums[0];
       int prev2=0;
       for(int i=1;i<n;i++){
            int op1=nums[i]+prev2;
            int op2=prev;
            int curri=max(op1,op2);
            prev2=prev;
            prev=curri;
       }
       return prev; 
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<nums.size()-1;i++){
            temp1.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++){
            temp2.push_back(nums[i]);
        }

        return max(help(temp1),help(temp2));

    }
};