class Solution {
public:
    void help(int i,vector<int>& jobDifficulty,vector<int>& diff,int x,int &ans){
        if(x==jobDifficulty.size() && i==diff.size()){
            int temp=0;
            for(int idx=0;idx<diff.size();idx++){
                temp+=diff[idx];
            }
            ans=min(ans,temp);
        }
        if(i>=diff.size() || x>=jobDifficulty.size()){
            return;
        }
        int remainingDays=diff.size()-i-1;
        int ele=jobDifficulty[x];
        for(int idx=x;idx<jobDifficulty.size()-remainingDays;idx++){
            ele=max(ele,jobDifficulty[idx]);
            diff[i]=ele;
            help(i+1,jobDifficulty,diff,idx+1,ans);
        }
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n)return -1;
        vector<int> diff(d,0);
        int ans=INT_MAX;
        help(0,jobDifficulty,diff,0,ans);
        return ans;    
    }
};