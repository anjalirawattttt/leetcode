class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int maxPile=piles[0];
        for(int i=1;i<n;i++){
            maxPile=max(maxPile,piles[i]);
        }

        int l=1,r=maxPile;
        int ans=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            long long hours=0;
            for(int i=0;i<n;i++){
                hours+=(long long)(piles[i]+mid-1)/mid;
            }
            if(hours<=h){
                ans=mid;
                r=mid-1;
            } 
            else{
                l=mid+1;
            }
        }  
        return ans;
    }
};