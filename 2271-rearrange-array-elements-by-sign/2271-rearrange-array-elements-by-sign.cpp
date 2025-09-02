class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int n=nums.size();
        // int pos=0;
        // int i=0;
        // while(pos<n){
        //     if(nums[i]>0){
        //         swap(nums[i],nums[pos]);
        //         pos+=2;
        //         i++;
        //     }
        //     else{
        //         i++;
        //     }
        // } 
        // return nums;
        int n=nums.size();
        vector<int> ans(n);
        int pos=0,neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos+=2;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};