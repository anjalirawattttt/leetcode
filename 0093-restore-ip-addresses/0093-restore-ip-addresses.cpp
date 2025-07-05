class Solution {
public:
    void help(vector<string>& res,string temp,string s,int i,int n){        
        if(i==s.length() && n==0){
            res.push_back(temp);
            return;
        }
        if(i==s.length() || n==0 )return;

        
        for(int j=i ; j<s.length() && j-i<3 ;j++){
            string sub=s.substr(i, j - i + 1);
            if(sub.length()>1 && sub[0]=='0')return;
            int num=stoi(sub);
            if(num<=255){
                string withDot = (n==1) ? sub : sub+'.';
                help(res,temp+withDot,s,j+1,n-1);
            }
            else{
                break;
            }
                               
        }
        
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length()<4 || s.length()>12)return res;
        string temp="";
        help(res,temp,s,0,4);
        return res;   
    }
};