class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start,end;
        int n=nums.size(),i=0;
        if(n==0)return ans;
        while(i<n){
            if(i==0){
                start=nums[i];
                end=nums[i];
            }
            else if(nums[i]==end+1){
                end++;
            }
            else{
                string temp="";
                if(start==end){
                    temp=to_string(start);
                }
                else{
                    temp=to_string(start)+"->"+to_string(end);
                }
                ans.push_back(temp);
                start=nums[i];
                end=nums[i];
            }
            i++;
        }
        string temp="";
        if(start==end){
            temp=to_string(start);
        }
        else{
            temp=to_string(start)+"->"+to_string(end);
        }
        ans.push_back(temp);
        return ans;
            
    }
};