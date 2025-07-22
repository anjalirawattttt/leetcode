class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int hash[10001]={0};
        int l=0,r=0,ans=0,sum=0;
        while(l<n && r<n){
            if(hash[nums[l]]==1){
                sum-=nums[r];
                hash[nums[r]]=0;
                r++;
            }
            else{
                hash[nums[l]]=1;
                sum+=nums[l]; 
                l++;  
            }
            ans=max(ans,sum);
        }
        return ans;

    }
};