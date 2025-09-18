class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int ans=1;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int num:s){
            if(s.find(num-1)==s.end()){
                int count=1;
                int prev=num;
                while(s.find(prev+1)!=s.end()){
                    count++;
                    prev++;
                }
                ans=max(ans,count);
            }
        } 
        return ans; 
    }
};