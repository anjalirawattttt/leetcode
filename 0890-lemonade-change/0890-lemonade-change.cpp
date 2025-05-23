class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0,c10=0;
        for(int bill:bills){
            if(bill==5){
                c5++;
            }
            else if(bill==10){
                c10++;
                if(c5>0){
                    c5--;
                }
                else{
                    return false;
                }
            }
            else{
                if(c5>0 && c10>0){
                    c5--;
                    c10--;
                }
                else if(c5>2){
                    c5-=3;
                }
                else{
                    return false;
                }
            }

        }

        return true;
    }
};