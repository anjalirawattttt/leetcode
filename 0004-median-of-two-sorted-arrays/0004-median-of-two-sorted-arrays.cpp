class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)return findMedianSortedArrays(nums2,nums1);

        if( (n1+n2)%2==0 ){
            int left=(n1+n2)/2;
            int right=left;

            int l = max(0,left-n2) , h = min(n1,left);
            while(l<=h){
                int mid1=l+(h-l)/2;
                int mid2=left-mid1;
                int l1 = mid1>0 ? nums1[mid1-1] : INT_MIN ;
                int r1 = mid1==n1 ? INT_MAX : nums1[mid1] ; 
                int l2 =  mid2>0 ? nums2[mid2-1] : INT_MIN ;
                int r2 = mid2==n2 ? INT_MAX : nums2[mid2] ;
                if(l1<=r2 && l2<=r1){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else if(l1>r2){
                    h=mid1-1;
                }
                else{
                    l=mid1+1;
                }
            }
        } 
        else{
            int right=(n1+n2)/2;
            int left=right+1;

            int l = max(0,left-n2) , h = min(n1,left);
            while(l<=h){
                int mid1=l+(h-l)/2;
                int mid2=left-mid1;
                int l1 = mid1>0 ? nums1[mid1-1] : INT_MIN ;
                int r1 = mid1==n1 ? INT_MAX : nums1[mid1] ; 
                int l2 =  mid2>0 ? nums2[mid2-1] : INT_MIN ;
                int r2 = mid2==n2 ? INT_MAX : nums2[mid2] ;
                if(l1<=r2 && l2<=r1){
                    return max(l1,l2);
                }
                else if(l1>r2){
                    h=mid1-1;
                }
                else{
                    l=mid1+1;
                }
            }
        }
        return -1;    
    }
};