class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxEle=0,sum=0;

        for(int i=0;i<n;i++){
            maxEle=max(maxEle,nums[i]);
            sum+=nums[i];
        }

        int l=maxEle,r=sum;
        while(l!=r){
            int mid=l+(r-l)/2;
            int sub=1,temp=0;

            for(int i=0;i<n;i++){
                if(temp+nums[i]<=mid)temp+=nums[i];
                else {
                    sub++;
                    temp=nums[i];
                }
            }
            if(sub<=k)r=mid;
            else l=mid+1;

        }
        return l;
    }
};