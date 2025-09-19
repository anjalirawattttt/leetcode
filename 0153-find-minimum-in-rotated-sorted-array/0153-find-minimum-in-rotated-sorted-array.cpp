class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return min(nums[0],nums[1]);
        int l=0,r=n-1;
        int minEle=nums[0];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]<=nums[mid]){
                //first half sorted
                minEle=min(minEle,nums[l]);
                l=mid+1;
            }
            else{
                minEle=min(minEle,nums[mid]);
                r=mid-1;
            }
        }  
        return minEle;  
    }
};