class Solution {
public:
    void merge(int l,int mid,int h,vector<int> &nums,int &count){
        int n1=mid-l+1;
        int n2=h-mid;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i=0;i<n1;i++){
            left[i]=nums[l+i];
        }
        for(int i=0;i<n2;i++){
            right[i]=nums[mid+1+i];
        }

        //count pairs
        int i=0,j=0;
        while(j<n2 && i<n1){
            if((long long)left[i]>(2LL*right[j])){
                count+=n1-i;
                j++;
            }
            else{
                i++;
            }
        }

        int k=l;
        i=0,j=0;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                nums[k++]=left[i++];
            }
            else{
                nums[k++]=right[j++];
            }
        }
        while(i<n1){
            nums[k++]=left[i++];
        }
        while(j<n2){
            nums[k++]=right[j++];
        }
    }
    void mergeSort(int l,int h,vector<int> &nums,int &count){
        if(l<h){
            int mid = l + (h-l)/2 ;
            mergeSort(l,mid,nums,count);
            mergeSort(mid+1,h,nums,count);
            merge(l,mid,h,nums,count);
        }
    }
    int reversePairs(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        mergeSort(0,n-1,nums,count);
        return count;    
    }
};