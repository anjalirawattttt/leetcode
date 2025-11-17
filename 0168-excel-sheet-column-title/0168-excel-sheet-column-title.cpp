class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0){
            columnNumber--;
            int digit=columnNumber%26;
            ans=char('A'+digit)+ans;
            columnNumber=columnNumber/26;
        }
        return ans;    
    }
};