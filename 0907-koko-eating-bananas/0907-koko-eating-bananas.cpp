class Solution {
public:
    int getBananas(int lower,int upper,vector<int> piles, int h){
        int l=lower,r=upper,cap,result=upper;
        while(l<=r){
            cap=l+(r-l)/2;
            long long calHours=0;
            for(int &pile:piles){
                calHours+=(pile+cap-1LL)/cap;
            }
            if(calHours<=h){
                result=cap;
                r=cap-1;
            }
            else{
                l=cap+1;
            }
        }
        return result;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int lower=1,upper=piles[0];
        for(int &pile:piles){
            upper=max(upper,pile);
        }

        int capacity=getBananas(lower,upper,piles,h);
        return capacity;
    }
};