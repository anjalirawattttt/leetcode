class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile=0;
        for(int i=0;i<piles.size();i++){
            maxPile=max(maxPile,piles[i]);
        }    

        int l=1,r=maxPile;
        while(l!=r){
            int mid = l + (r-l)/2;
            int hours=0;
            for(int i=0;i<piles.size();i++){
                hours+=(piles[i]+mid-1)/mid;
            }
            if(hours<=h)r=mid;
            else l=mid+1;

        }
        return l;
    }
};