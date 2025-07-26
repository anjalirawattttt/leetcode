class Solution {
public:
    int minInsertions(string s) {
        //longest palindromic subsequence
        int n=s.length();
        string s2="";
        for(int i=n-1;i>=0;i--){
            s2+=s[i];
        }
        vector<int> prev(n+1,0);

        for(int i1=1;i1<=n;i1++){
            vector<int> curr(n+1,0);
            for(int i2=1;i2<=n;i2++){
                if(s[i1-1]==s2[i2-1]){
                    curr[i2]=1+prev[i2-1];
                }
                //not match
                else{
                    curr[i2]=max(prev[i2],curr[i2-1]);
                }
            }
            prev=curr;
        }



        return n-prev[n]; 
    }
};