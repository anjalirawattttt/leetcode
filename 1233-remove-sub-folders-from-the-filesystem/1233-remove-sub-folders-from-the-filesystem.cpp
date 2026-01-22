class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n=folder.size();
        int i=0,j=1;  
        vector<string> ans;
        while(j<n){
            int n1=folder[i].length();
            int n2=folder[j].length();
            if(folder[i]==folder[j].substr(0,n1) && n2>n1 && folder[j][n1]=='/'){
                j++;
            }
            else{
                ans.push_back(folder[i]);
                i=j;
                j++;
            }
        }
        if(i<n)ans.push_back(folder[i]);
        return ans;
    }
};