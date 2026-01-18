class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(long long)m*k)return -1;
        int maxBloomDay=bloomDay[0];
        for(int i=1;i<n;i++){
            maxBloomDay=max(maxBloomDay,bloomDay[i]);
        }
        int ans=-1;
        int l=1,r=maxBloomDay;    
        while(l<=r){
            int mid = l + (r-l)/2;
            int flowers=0;
            int bouqets=0;
            for(int i=0;i<n;i++){
                while(i<n && bloomDay[i]<=mid){
                    flowers++;
                    i++;
                }
                if(flowers>=k){
                    bouqets+=flowers/k;
                }
                flowers=0;
            }

            if(bouqets>=m){
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