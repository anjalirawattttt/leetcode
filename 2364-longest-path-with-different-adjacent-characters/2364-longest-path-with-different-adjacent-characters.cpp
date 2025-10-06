class Solution {
public:
    int help(int prev,int i,vector<vector<int>> &adj,string &s,int &ans){
        int largest=0;
        int secondLargest=0;
        for(auto &v:adj[i]){
            int x=help(i,v,adj,s,ans);
            if(x>largest){
                secondLargest=largest;
                largest=x;
            }
            else if(x>secondLargest){
                secondLargest=x;
            }
        }
        ans=max(ans,1+largest+secondLargest);
        if(prev!=-1 && s[prev]==s[i])return 0;
        return max(1,1+largest);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=s.length();
        vector<vector<int>> adj(n);    
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        int ans=0;
        help(-1,0,adj,s,ans);
        return ans;
    }
};