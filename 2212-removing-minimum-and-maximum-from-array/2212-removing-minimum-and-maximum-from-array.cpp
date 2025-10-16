class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int ans=INT_MAX;
        int minEle=0;
        int maxEle=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[minEle])minEle=i;
            if(nums[i]>nums[maxEle])maxEle=i;
        }
        int temp=max(minEle,maxEle)+1;
        ans=min(ans,temp);
        temp=min(minEle,maxEle)+1+n-max(minEle,maxEle);
        ans=min(ans,temp);
        temp=n-min(minEle,maxEle);
        ans=min(ans,temp);
        return ans;     
    }
};