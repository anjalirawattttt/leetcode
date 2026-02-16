class Solution {
public:
    void dfs(string &email,unordered_set<string> &visited,unordered_map<string,vector<string>> &adj,vector<string> &temp){
        visited.insert(email);
        temp.push_back(email);
        for(auto &nbr:adj[email]){
            if(visited.find(nbr)==visited.end()){
                dfs(nbr,visited,adj,temp);
            }
        }
    }
    //dfs
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> emailToName;
        unordered_map<string,vector<string>> adj;

        for( auto & account : accounts){
            string name = account[0];
            for(int i=1;i<account.size();i++){
                string email=account[i];
                emailToName[email]=name;
                if(i>1){
                    adj[account[i]].push_back(account[1]);
                    adj[account[1]].push_back(account[i]);
                }
            }
        } 

        unordered_set<string> visited;
        vector<vector<string>> ans;
        //dfs

        for( auto &p : emailToName ){
            string email = p.first;
            if(visited.find(email)==visited.end()){
                vector<string> temp;
                dfs(email,visited,adj,temp);
                sort(temp.begin(),temp.end());
                temp.insert(temp.begin(),emailToName[email]);
                ans.push_back(temp);
            }
        }   

        return ans; 

    }
};