class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();  
        int candidate=-1;
        int freq=0; 
        for(int i=0;i<n;i++){
            if(candidate==-1){
                candidate=nums[i];
                freq=1;
            }
            else if(nums[i]==candidate){
                freq++;
            }
            else{
                freq--;
            }
            if(freq==0){
                candidate=-1;
            }
        } 
        return candidate;
    }
};