class Solution {
public:
    int findParent(int node,vector<int>& parent){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node],parent);//compression
    }
    void unionBySize(int u,int v,vector<int>& parent,vector<int>& size){
        int pu=findParent(u,parent);
        int pv=findParent(v,parent);
        if(pu==pv)return;
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];   
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //accounts from 0 to n-1
        int n=accounts.size();
        vector<int> parent(n);
        vector<int> size(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }  


        unordered_map<string,int> owner;//email->which account    
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(owner.find(email)==owner.end()){
                    owner[email]=i;
                }
                else{
                    unionBySize(i,owner[email],parent,size);
                }
            }
        } 

        vector<vector<string>> mergedAccounts(n);
        for(auto &[mail,o]:owner){
            int p=findParent(o,parent);
            mergedAccounts[p].push_back(mail);
        }

        vector<vector<string>> res;

        for(int i=0;i<n;i++){
            if(mergedAccounts[i].size()!=0){
                string name=accounts[i][0];
                mergedAccounts[i].insert(mergedAccounts[i].begin(),name);
                sort(mergedAccounts[i].begin()+1,mergedAccounts[i].end());
                res.push_back(mergedAccounts[i]);
            }
        }
        

        return res; 
    }
};