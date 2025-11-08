class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(candidate==-1){
                candidate=nums[i];
                count++;
                continue;
            }
            if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
                if(count==0)candidate=-1;
            }
        }    
        return candidate;
    }
};