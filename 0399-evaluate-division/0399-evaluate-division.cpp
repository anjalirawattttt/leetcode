class Solution {
public:
    double dfs(string &s,string &d,unordered_map<string,vector<pair<string,double>>> &m,unordered_set<string> &st){
        if(s==d)return 1.0;
        for(auto &p:m[s]){
            if(st.find(p.first)==st.end()){
                st.insert(p.first);
                double ans=p.second*dfs(p.first,d,m,st);
                if(ans>0.0)return ans;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n1=equations.size();
        int n2=queries.size();
        unordered_map<string,vector<pair<string,double>>> m;
        for(int i=0;i<n1;i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        } 

        vector<double> ans(n2);
        for(int i=0;i<n2;i++){
            if(m.find(queries[i][0])==m.end() || m.find(queries[i][1])==m.end()){
                ans[i]=-1.0;
                continue;
            }
            if(queries[i][0]==queries[i][1]){
                ans[i]=1.0;
                continue;
            }
            unordered_set<string> st;
            ans[i]=dfs(queries[i][0],queries[i][1],m,st);            
        }
        return ans;

    }
};