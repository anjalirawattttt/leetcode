class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;    
        int ele=nums[0];
        int n=nums.size();
        int l=1,r=1;
        while(l<n && r<n){
            if(nums[l]==ele){
                count++;
            }
            else if(nums[l]<ele){
                if(count==1){
                    while(r<n && nums[r]<ele){
                        r++;
                    }
                    if(r<n){
                        if(nums[r]==ele){                            
                            count++;
                            swap(nums[l],nums[r]);
                        }
                        else if(nums[r]>ele){                        
                            count=1;
                            ele=nums[r];
                            swap(nums[l],nums[r]);    
                        }
                    }
                }
                else if(count==2){
                    while(r<n && nums[r]<=ele){
                        r++;
                    }
                    if(r<n){
                        ele=nums[r];
                        count=1;
                        swap(nums[l],nums[r]);
                    }
                }
            }
            else{
                count=1;
                ele=nums[l];
            }
            if(count>2){
                while(r<n && nums[r]<=ele){
                    r++;
                }
                if(r<n){
                    ele=nums[r];
                    count=1;
                    swap(nums[l],nums[r]);
                }
            }
            if(r==n)return l;
            l++;
        }
        return l;
    }
};