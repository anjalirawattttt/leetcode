class Solution {
public:
    int help(int parent,int curr,vector<vector<int>> &adj,string &s,int &ans){
        int largest=0;
        int secondLargest=0;
        for(auto &child:adj[curr]){
            if(child==parent)continue;
            int x=help(curr,child,adj,s,ans);
            if(x>largest){
                secondLargest=largest;
                largest=x;
            }
            else if(x>secondLargest){
                secondLargest=x;
            }
        }
        ans=max(ans,1+largest+secondLargest);
        if(parent!=-1 && s[parent]==s[curr])return 0;
        return 1+largest;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=s.length();
        vector<vector<int>> adj(n);    
        for(int i=1;i<n;i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int ans=0;
        help(-1,0,adj,s,ans);
        return ans;
    }
};