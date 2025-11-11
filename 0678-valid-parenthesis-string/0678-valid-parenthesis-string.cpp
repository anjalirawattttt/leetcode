class Solution {
public:
    bool checkValidString(string s) {
        int sum=0,maxSum=0;
        for(char &c:s){
            if(c=='('){
                sum++;
                maxSum++;
            }
            else if(c==')'){
                sum--;
                maxSum--;
            }
            else{
                maxSum++;
                sum--;    
            }
            if(maxSum<0)return false;
        } 
        if(sum<=0 && maxSum>=0)return true; 
        return false;  
    }
};