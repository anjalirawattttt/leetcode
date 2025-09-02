class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,n=nums.size();  
        int ans=0; 
        while(i<n){
            j=i;
            while(i<n && nums[i]==1)i++;
            ans=max(ans,i-j);
            i++;
        } 
        return ans;      
    }
};