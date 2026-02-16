class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector <double> ans;
        int n = equations.size();   
        unordered_map <string , vector<pair<string,double>> > adj; 
        for( int i = 0 ; i < n ; i++ ){
            string s1=equations[i][0];
            string s2=equations[i][1];
            double value=values[i];
            adj[s1].push_back({s2,value});
            adj[s2].push_back({s1,1.0/value});
        }

        for( auto &query: queries){
            string s1=query[0];
            string s2=query[1];

            if(adj.find(s1)==adj.end() || adj.find(s2)==adj.end()){
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            queue<pair<string,double>> q;
            q.push({s1,1.0});
            visited.insert(s1);
            bool found=false;
            while(!q.empty()){
                auto [str1,v1]=q.front();
                if(str1==s2){
                    ans.push_back(v1);
                    found=true;
                    break;
                }
                q.pop();
                for(auto &[str2,v2] : adj[str1]){
                    if(visited.find(str2)==visited.end()){
                        visited.insert(str2);
                        q.push({str2,v1*v2});
                    }
                }
            }
            if(!found){
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};