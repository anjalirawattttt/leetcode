class Solution {
public:

    bool compare(string currString,vector<int>& selected){
        vector<int> selfCheck(26,0);
        for(char &ch:currString){
            if(selfCheck[ch-'a']==1)return false;
            selfCheck[ch-'a']=1;
        }
        for(char &ch:currString){
            if(selected[ch-'a']==1)return false;
        }
        return true;
    }


    int help(int i,vector<string>& arr,vector<int>& selected,int len){
        if(i==arr.size())return len;
        string currString=arr[i];
        if(compare(currString,selected)){
            //pick
            for(char &ch:currString){
                selected[ch-'a']=1;
            }
            len+=currString.length();
            int op1=help(i+1,arr,selected,len);
            //not pick
            for(char &ch:currString){
                selected[ch-'a']=0;
            }
            len-=currString.length();
            int op2= help(i+1,arr,selected,len);
            
            return max(op1,op2);

        }
        else{
            //not pick
            return help(i+1,arr,selected,len);
        }
    }
    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return help(0,arr,selected,0);
    }
};