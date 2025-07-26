class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<int> prev(n2+1,0);

        for(int i1=1;i1<=n1;i1++){
            vector<int> curr(n2+1,0);
            for(int i2=1;i2<=n2;i2++){
                if(text1[i1-1]==text2[i2-1]) curr[i2]=1+prev[i2-1];
                //not match
                else{
                    curr[i2]=max(prev[i2],curr[i2-1]);
                }
            }
            prev=curr;
        }
        return prev[n2];      
    }

    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        int lcs=longestCommonSubsequence(word1,word2);  
        int ans=0;
        ans+=n1-lcs;
        ans+=n2-lcs;
        return ans; 
    }
};