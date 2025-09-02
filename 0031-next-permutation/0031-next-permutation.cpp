class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--){
            //find the break point
            if(nums[i-1]<nums[i]){
                // int temp=nums[i-1];
                for(int j=nums.size()-1;j>=i;j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[i-1],nums[j]);
                        break;
                    }
                }  
                sort(nums.begin()+i,nums.end()); 
                return;
            }
        } 

        sort(nums.begin(),nums.end());  
    }
};