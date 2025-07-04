class Solution {
public:
    //n - how many left to open
    //i - how many are currently open
    void help(vector<string>& res,string& temp,int n,int i){
        if(n==0 && i==0){
            res.push_back(temp);
            return;
        }

        if(i>0){
            temp+=')';
            help(res,temp,n,i-1);
            temp.pop_back();

        }

        


        if(n>0){
            temp+='(';
            help(res,temp,n-1,i+1);
            temp.pop_back();
        }
        

    }


    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        help(res,temp,n,0);
        return res;   
    }
};