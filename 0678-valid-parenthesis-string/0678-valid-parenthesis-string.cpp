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
            if(sum<0)sum=0;
            if(maxSum<0)return false;
        } 
        return sum==0;  
    }
};