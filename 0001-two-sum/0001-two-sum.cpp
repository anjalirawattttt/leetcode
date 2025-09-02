class Solution {
public:
    int search(vector<int> &v,int n,int x){
        for(int i=0;i<n;i++){
            if(v[i]==x)return i;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=1;i<nums.size();i++){
            int j=search(nums,i,target-nums[i]);
            if(j!=-1)return {j,i};
        }
        return {-1,-1};
    }
};