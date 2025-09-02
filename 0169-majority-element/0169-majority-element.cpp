class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore voting algorithm
        int count=0,candidate;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate=nums[i];
                count++;
            }
            else{
                if(nums[i]==candidate)count++;
                else count--;
            }
        }
        return candidate;    
    }
};