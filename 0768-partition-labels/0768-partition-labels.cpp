class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        int n=s.length();
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }

        vector<int> ans;
        int i=1;
        int limit=m[s[0]];
        int sum=0;
        while(i<n){
            if(limit<i){
                if(ans.empty()){
                    ans.push_back(limit+1);
                    sum+=limit+1;
                }
                else{
                    ans.push_back(limit-sum+1);
                    sum+=limit-sum+1;
                } 
            }
            limit=max(limit,m[s[i]]);
            i++;
        } 
        if(ans.empty()){
            ans.push_back(limit+1);
            sum+=limit+1;
        }
        else{
            ans.push_back(limit-sum+1);
            sum+=limit-sum+1;
        } 
        return ans;   
    }
};