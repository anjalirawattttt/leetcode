class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //ceiling division   
        int n=nums.size();

        int maxNum=0;
        for(int i=0;i<n;i++)maxNum=max(maxNum,nums[i]);

        int l=1,r=maxNum;
        while(l!=r){
            int mid=l+(r-l)/2;
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum<=threshold)r=mid;
            else l=mid+1;
        }
        return l;
    }
};