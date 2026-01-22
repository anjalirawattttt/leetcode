class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int maxPrice=costs[0];
        for(int i=1;i<n;i++){
            maxPrice=max(maxPrice,costs[i]);
        }
        //counting sort
        vector<int> freq(maxPrice+1,0);
        for(int i=0;i<n;i++){
            freq[costs[i]]++;
        }

        int ans=0;
        for(int i=0;i<=maxPrice;i++){
            if(freq[i]>0 && coins>=i){
                int howMany=min(freq[i],coins/i);
                ans+=howMany;
                coins-=i*howMany;
            }
            else if(freq[i]>0)break;
        }
        return ans;


    }
};