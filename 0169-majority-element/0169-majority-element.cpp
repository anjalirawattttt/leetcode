class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(count==0)curr=nums[i];
            if(nums[i]==curr){
                count++;
            }
            else{
                count--;
            }            
        }
        return curr;
    }
};