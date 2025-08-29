class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n)return -1;

        int maxDay=0;
        for(int i=0;i<n;i++)maxDay=max(maxDay,bloomDay[i]);

        int l=1,r=maxDay;
        while(l!=r){
            int mid=l+(r-l)/2;
            int bouqets=0,flowers=0;

            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    flowers++;
                    if(flowers==k){
                        bouqets++;
                        flowers=0;
                    }
                }
                else{
                    flowers=0;
                }
            }

            if(bouqets>=m)r=mid;
            else l=mid+1;
        }
        return l;
    }
};