class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;

        int temp=0;
        int i=n-1; 
        while(i>=0){
            if(nums[i]>=temp){
                i--;
                temp=1;
            }else{
                temp++;
                i--;
            }
        }   
        if(temp==1)return true;
        return false;
    }
};