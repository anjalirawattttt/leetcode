class Solution {
public:
    void help(string temp,vector<string>& ans,int i,string &num,int target,long long res,long long prev){
        if(i>=num.length()){
            if(res==target){
                ans.push_back(temp);
            }
            return;
        }

        for(int j=i;j<num.length();j++){
            string np=num.substr(i,j-i+1);
            if(np.length()>1 && np[0]=='0')return;
            help(temp + '+' + np , ans , j+1 , num , target , res+stoll(np) , 1*stoll(np) ); 
            help(temp + '-' + np , ans , j+1 , num , target , res-stoll(np) , -1*stoll(np) ); 
            long long newValue = ( res - prev ) + (prev*stoll(np));
            help(temp + '*' + np , ans , j+1 , num , target , newValue , (prev*stoll(np))  );    
        }        
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        for(int i=0;i<num.length();i++){
            string temp=num.substr(0,i+1);
            if(temp.length()>1 && temp[0]=='0')continue;
            help(temp,ans,i+1,num,target,stoll(temp),stoll(temp));    
        }
        return ans;
    }
};