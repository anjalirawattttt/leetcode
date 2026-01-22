class Solution {
public:
    int minPair(vector<int> &nums){
        int n=nums.size();
        int minSum=INT_MAX;
        int pos=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]+nums[i+1]<minSum){
                minSum=nums[i]+nums[i+1];
                pos=i;
            }
        }
        return pos;
    }
    void mergePair(vector<int> &nums,int pos){
        nums[pos]+=nums[pos+1];
        nums.erase(nums.begin()+pos+1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int operations=0;
        while(true){
            if(is_sorted(nums.begin(),nums.end()))return operations;
            int i=minPair(nums);
            mergePair(nums,i);
            operations++;
        }
        return operations;    
    }
};