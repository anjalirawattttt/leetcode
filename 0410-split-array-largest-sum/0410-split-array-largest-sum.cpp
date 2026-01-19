class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int maxEle=nums[0];
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxEle=max(maxEle,nums[i]);
        }

        int ans=-1;

    
        int l=maxEle,r=sum;
        while(l<=r){
            int mid = l + (r-l)/2 ;
            int s=0,bags=0;
            for(int i=0;i<n;i++){
                if(s+nums[i]<=mid){
                    s+=nums[i];
                }
                else{
                    bags++;
                    s=nums[i];
                }
            }
            bags++;

            if(bags<=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;

    }
};