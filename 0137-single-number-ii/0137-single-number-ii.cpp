class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bitCount=0;bitCount<32;bitCount++){
            int count=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&(1<<bitCount))count++;
            }
            if(count%3==1){
                ans=ans|(1<<bitCount);
            }
        }
        return ans;  
    }
};