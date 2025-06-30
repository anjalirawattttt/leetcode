class Solution {
public:
    bool helper(vector<int>& nums,int target,vector<bool>& visited,int bSum,int k,int i){
        if(k==1)return true;
        if(bSum==target){
            return helper(nums,target,visited,0,k-1,0);
        }
        

        for(int j=i;j<nums.size();j++){
            if(!visited[j] && bSum+nums[j]<=target){
                visited[j]=true;
                if(helper(nums,target,visited,bSum+nums[j],k,j+1))return true;  
                visited[j]=false;
                if(bSum==0)return false;
            }
            
        }
        return false;

    }
    

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int &num:nums){
            sum+=num;
        }
        if(sum%k!=0)return false;
        int target=sum/k;

        

        sort(nums.rbegin(),nums.rend());
        if(nums[0]>target)return false;

        int n=nums.size();
        vector<bool> visited(n,false); 

        return helper(nums,target,visited,0,k,0); 

    }
};