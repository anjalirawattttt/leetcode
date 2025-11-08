class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool canJump=true;
        int temp=1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=temp){
                canJump=true;
                temp=1;
            }
            else{
                canJump=false;
                temp++;
            }
        }  
        return canJump;  
    }
};