class Solution {
public:
    void merge(vector<int> &arr,int l,int m,int r,int &ans){
        int n1=m-l+1;
        int n2=r-m;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i=0;i<n1;i++)left[i]=arr[l+i];
        for(int i=0;i<n2;i++)right[i]=arr[m+1+i];

        int i=0,j=0;
        while(i<n1){
            while(j<n2 && left[i]>(long long)2*right[j]){
                j++;
            }
            ans+=j;
            i++;
        }





        i=0;j=0;
        int k=l;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k++]=left[i++];
            }
            else{
                arr[k++]=right[j++];
            }
        }
        while(i<n1){
            arr[k++]=left[i++];
        }
        while(j<n2){
            arr[k++]=right[j++];
        }
    }

    void mergeSort(vector<int> &arr,int l,int r,int &ans){
        if(l<r){
            int m=l+(r-l)/2;
            mergeSort(arr,l,m,ans);
            mergeSort(arr,m+1,r,ans);
            merge(arr,l,m,r,ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        mergeSort(nums,0,n-1,ans);
        return ans;    
    }
};