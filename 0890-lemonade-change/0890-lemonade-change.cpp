class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_5=0,bill_10=0,bill_20=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==20){
                bill_20++;
                if(bill_10>0 && bill_5>0){
                    bill_10--;
                    bill_5--;
                }
                else if(bill_5>2){
                    bill_5-=3;
                }
                else return false;
            }
            else if(bills[i]==10){
                bill_10++;
                if(bill_5>0){
                    bill_5--;
                }
                else return false;
            }
            else{
                bill_5++;    
            }
        }
        return true;

    }
};