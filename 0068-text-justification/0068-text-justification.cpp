class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0,n=words.size();
        while(i<n){
            vector<string> v;
            int count=0;
            while(i<n && words[i].length()+(v.size())+count<=maxWidth){
                v.push_back(words[i]);
                count+=words[i].length();
                i++;
            }
            if(i==n){
                int spaces=maxWidth-count;
                string temp="";
                for(int i=0;i<v.size();i++){
                    if(i==v.size()-1){
                        temp+=v[i];
                        break;
                    }
                    temp+=v[i];
                    temp+=' ';
                    spaces--;
                } 
                temp += string(spaces, ' ');
                ans.push_back(temp);   
            }
            else{
                int k=v.size();
                int spaces=maxWidth-count;
                if(k==1){
                    string temp="";
                    temp+=v[0];
                    temp+=string(spaces,' ');
                    ans.push_back(temp);
                    continue;
                }
                int eachSpace=0;
                if(k>1)eachSpace=spaces/(k-1);
                int extraSpace=0;
                if(k>1)extraSpace=spaces%(k-1);
                string temp="";
                for(int i=0;i<v.size();i++){
                    if(i==v.size()-1){
                        temp+=v[i];
                        break;
                    }
                    temp+=v[i];
                    temp += string(eachSpace, ' ');  
                    if(extraSpace){
                        temp+=' ';
                        extraSpace--;
                    }
                }
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};