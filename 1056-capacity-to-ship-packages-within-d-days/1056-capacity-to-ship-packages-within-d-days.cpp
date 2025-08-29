class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int maxWeight=0,totalWeight=0;
        for(int i=0;i<n;i++){
            maxWeight=max(maxWeight,weights[i]);
            totalWeight+=weights[i];
        }

        int l=maxWeight,r=totalWeight;
        while(l!=r){
            int mid=l+(r-l)/2;
            int d=1,loaded=0;
            
            for(int i=0;i<n;i++){
                if(loaded+weights[i]<=mid){
                    loaded+=weights[i];
                }
                else{
                    d++;
                    loaded=weights[i];
                }
            }
            if(d<=days)r=mid;
            else l=mid+1;
        }
        return l;
    }
};