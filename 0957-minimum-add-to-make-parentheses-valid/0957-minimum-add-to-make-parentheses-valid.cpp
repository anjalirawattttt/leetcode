class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        if(n==0)return 0;  
        int count=0;
        int ans=0;
        for(char &c:s){
            if(c=='('){
                count++;
            }   
            else{
                count--;
            } 
            if(count<0){
                ans+=abs(count);
                count=0;
            }
        }  
        return ans+abs(count);
    }
};