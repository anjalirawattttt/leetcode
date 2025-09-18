class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        //convert it to 2 sum problem
        //num1+num2+num3=0
        //num2+num3=-num1
        int i=0,j,k;
        while(i<n-2){
            int sum=-1*nums[i];
            j=i+1;
            k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==sum){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<n-1 && nums[j]==nums[j+1])j++;
                    while(k>0 && nums[k]==nums[k-1])k--;
                    k--;
                }
                else if(nums[j]+nums[k]<sum){
                    j++;
                }
                else{
                    k--;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1])i++;
            i++;
        }
        return ans;
    }
};