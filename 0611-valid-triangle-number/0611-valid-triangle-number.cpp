class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(n<3)return ans;
        sort(nums.begin(),nums.end());
        int i,j;
        for(int k=n-1;k>=2;k--){
            i=0;
            j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    ans+=j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};