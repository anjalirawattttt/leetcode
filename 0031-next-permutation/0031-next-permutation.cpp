class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        while(i>0){
            if(nums[i-1]<nums[i]){
                break;
            }
            i--;
        } 
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int refernce=i-1;
        int justGreater=i;
        while(i<n){
            if(nums[i]>nums[refernce] && nums[i]<nums[justGreater]){
                justGreater=i;
            }
            i++;
        }
        swap(nums[refernce],nums[justGreater]);
        sort(nums.begin()+refernce+1,nums.end());

    }
};