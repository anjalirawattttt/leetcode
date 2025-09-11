class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> s;
        vector<bool> visited(n,false);
        
        for(int idx=0;idx<2*n;idx++){
            int i=(idx%n);
            if(s.empty()){
                s.push(i);
            }
            else if(nums[i]>nums[s.top()]){
                while(!s.empty() && nums[i]>nums[s.top()]){
                    visited[s.top()]=true;
                    ans[s.top()]=nums[i];
                    s.pop();
                }
                if(!visited[i]){
                    s.push(i);
                    visited[i]=true; 
                }
            }
            else{
                if(!visited[i]){
                    s.push(i);
                    visited[i]=true; 
                }    
            }
        }
        while(!s.empty()){
            ans[s.top()]=-1;
            s.pop();
        }

        
        return ans;    
    }
};