class Solution {
public:
    void generateAllSubsetSum(int start,int i,int sum,vector<vector<int>> &temp,vector<int>& nums,int cnt){
        if(i<start){
            temp[cnt].push_back(sum);
            return ;
        }
        //take
        generateAllSubsetSum(start,i-1,sum+nums[i],temp,nums,cnt+1);
        //not take
        generateAllSubsetSum(start,i-1,sum,temp,nums,cnt);
    }
    
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int n1=n/2;
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        vector<vector<int>> temp(n1+1);
        generateAllSubsetSum(0,n1-1,0,temp,nums,0);
        vector<vector<int>> left=temp;

        for(auto &v:temp)v.clear();
        
        generateAllSubsetSum(n1,n-1,0,temp,nums,0);
        vector<vector<int>> right=temp;


        for (int i = 0; i <= n1; i++)sort(right[i].begin(), right[i].end());



        int ans=INT_MAX;
        for(int l=0;l<=n1;l++){
            int r=n1-l;
            for(int i=0;i<left[l].size();i++){
                int low=0,high=right[r].size()-1;
                while(low<=high){
                    int mid = low + (high-low)/2;
                    int a=left[l][i]+right[r][mid];
                    int b=totalSum-a;
                    if(a<=b){
                        ans=min(ans,abs(a-b));
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }

                low=0,high=right[r].size()-1;
                while(low<=high){
                    int mid = low + (high-low)/2;
                    int a=left[l][i]+right[r][mid];
                    int b=totalSum-a;
                    if(a>=b){
                        ans=min(ans,abs(a-b));
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
            }
        }
        return ans;
    }
};