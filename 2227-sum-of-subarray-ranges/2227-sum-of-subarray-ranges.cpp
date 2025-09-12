class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<int> pse(n);
        vector<int> nse(n);
        vector<int> pge(n);
        vector<int> nge(n);


        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i])s.pop();
            pse[i]=s.empty()?i+1:i-s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i])s.pop();
            nse[i]=s.empty()?n-i:s.top()-i;
            s.push(i);
        }
        while(!s.empty())s.pop();


        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i])s.pop();
            pge[i]=s.empty()?i+1:i-s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i])s.pop();
            nge[i]=s.empty()?n-i:s.top()-i;
            s.push(i);
        }

        for(int i=0;i<n;i++){
            ans += nums[i]*( ((long long)nge[i]*pge[i]) - ((long long)nse[i]*pse[i]) );
        }
    

        return ans;   
    }
};