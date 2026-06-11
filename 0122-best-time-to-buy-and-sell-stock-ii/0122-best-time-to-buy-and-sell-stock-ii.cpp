class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 ;
        int buy = -1 ;
        int sell = -1 ;
        int n = prices.size();

        for( int i = 0 ; i < n ; i++ ){
            if( buy == -1 ){
                buy = prices[i];
                sell = prices[i];
                continue;
            }

            if(prices[i-1] > prices[i]){
                //sell
                maxProfit += sell - buy ;
                buy = prices[i] ;
                sell = prices[i] ;
            }
            else{
                sell = prices[i] ;
            }
        }

        if(buy!=-1){
            maxProfit += sell - buy ;

        }

        return maxProfit ;    
    }
};