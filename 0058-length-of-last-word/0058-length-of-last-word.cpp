class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,count=0;
        int i=0,n=s.length();
        while(i<n){
            if(s[i]==' '){
                ans=count;
                count=0;
                while(s[i]==' ')i++;
                i--;
            }
            else{
                count++;
            }
            i++;
        }
        if(count!=0)return count;
        return ans;
    }
};