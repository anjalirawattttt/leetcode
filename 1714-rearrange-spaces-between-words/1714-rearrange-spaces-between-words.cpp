class Solution {
public:
    string reorderSpaces(string text) {
        string ans="";
        vector<string> words;
        int n=text.length();
        int i=0,spaces=0;
        string temp="";
        //count spaces
        //count words and store them
        while(i<n){
            if(text[i]==' '){
                if(!temp.empty()){
                    words.push_back(temp);
                    temp="";
                }
                spaces++;
            }
            else{
                temp+=text[i];
            }
            i++;
        }
        if(!temp.empty()){
            words.push_back(temp);
            temp="";
        }
        //edge case
        if(spaces==0)return text;
        //edge case
        if(words.size()==1){
            ans+=words[0];
            while(spaces--)ans+=' ';
            return ans;
        }
        int eachSpace=spaces/(words.size()-1);
        int remainingSpace= spaces % (words.size()-1) ;
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            if(i<words.size()-1){
                for(int i=0;i<eachSpace;i++)ans+=' ';
            }            
        }
        for(int i=0;i<remainingSpace;i++)ans+=' ';
        return ans;
    }
};