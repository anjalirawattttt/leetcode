class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        bool nPresent=false;
        for(int i=0;i<n;i++){
            if(abs(nums[i])==n){
                nPresent=true;
                continue;    
            }
            nums[abs(nums[i])]*=-1;
        }
        if(!nPresent)return n;
        for(int i=0;i<n;i++){
            if(nums[i]>0)return i;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0)return i;
        }
        return -1;

    }
};