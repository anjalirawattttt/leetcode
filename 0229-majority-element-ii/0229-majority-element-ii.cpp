class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();

        int cand1,cand2,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(cand1==nums[i])cnt1++;
            else if(cand2==nums[i])cnt2++;
            else if(cnt1==0){
                cand1=nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                cand2=nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        int x=n/3;
        cnt1=0;cnt2=0;
        for(int i=0;i<n;i++){
            if(cand1==nums[i])cnt1++;
            else if(cand2==nums[i])cnt2++;
        }

        if(cnt1>x)ans.push_back(cand1);
        if(cnt2>x)ans.push_back(cand2);

        return ans;
    }
};