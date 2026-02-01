class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n=nums.size();
        int maxEle=nums[0];
        for(int i=0;i<n;i++){
            maxEle=max(maxEle,nums[i]);        
        }

        long long l=1,r=1e5;
        int ans=-1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long temp=0;
            for(int i=0;i<n;i++){
                 temp+=(nums[i]+mid-1)/mid;
            }
            if(temp<=(mid*mid)){
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