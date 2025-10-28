class Solution {
public:
    string countAndSay(int n) {    
        string ans="1";
        for(int i=1;i<=n-1;i++){
            string temp="";
            int idx=0;
            while(idx<ans.length()){
                char c=ans[idx];
                int count=1;
                while(idx<ans.length()-1 && ans[idx]==ans[idx+1]){
                    count++;
                    idx++;
                } 
                temp+= to_string(count) ;
                temp+= c;
                idx++;
            }
            ans=temp;  
        }
        return ans;    
    }
};