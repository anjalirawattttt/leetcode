class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n+1,0);
        int ans=-1;

        for(int i=0;i<trust.size();i++){
            trusted[trust[i][0]]--;
            trusted[trust[i][1]]++;    
        }
        
        int count=0;
        for(int i=1;i<n+1;i++){
            if(trusted[i]==n-1){
                ans=i;
                count++;
            }
        } 

        if(count==1)return ans;
        return -1;

    }
};