class Solution {
public:
    bool check(vector<int>& nums) {
        int inversions=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])inversions++;
        }



        if(inversions>1)return false;
        else return true;  
    }
};