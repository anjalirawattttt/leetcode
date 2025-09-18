class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        int ans=1,count=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])continue;
            if(nums[i]==prev+1){
                count++;
                prev=nums[i];
            }
            else{
                count=1;
                prev=nums[i];
            }
            ans=max(ans,count);
        } 
        return ans;  
    }
};