class Solution {
public:
    bool checkValidString(string s) {
        int minn=0;
        int maxx=0;
        for(char &c:s){
            if(c=='('){
                minn++;
                maxx++;
            }
            else if(c==')'){
                minn--;
                maxx--;
            }
            else{
                minn--;
                maxx++;
            }
            if(minn<0)minn=0;
            if(maxx<0)return false;
        }
        return minn==0;
    }
};