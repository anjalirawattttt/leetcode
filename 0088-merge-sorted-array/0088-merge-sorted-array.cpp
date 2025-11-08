class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m+n-1;i>=n;i--){
            nums1[i]=nums1[i-n];
        }
        // for(int i=0;i<m+n;i++)cout<<nums1[i]<<" ";
        int i=n,j=0,idx=0;
        while(i<m+n && j<n){
            if(nums1[i]<=nums2[j]){
                nums1[idx++]=nums1[i];
                i++;
            }
            else{
                nums1[idx++]=nums2[j];
                j++;
            }
        }
        while(i<m+n){
            nums1[idx++]=nums1[i];
            i++;
        }
        while(j<n){
            nums1[idx++]=nums2[j];
            j++;
        }
    }
};