class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n);
        vector<int> right(n);
        long long maxSum=0,minSum=0;  
        stack<int> s; 
        //CALCULATE MINSUM 
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i])s.pop();
            left[i]=s.empty()?i+1:i-s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            right[i]=s.empty()?n-i:s.top()-i;
            s.push(i);
        }
        for(int i=0;i<n;i++){
            minSum=(minSum+(1LL*arr[i]*left[i]*right[i]));
        }
        //CALCULATE MAXSUM
        while(!s.empty())s.pop();
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]<arr[i])s.pop();
            left[i]=s.empty()?i+1:i-s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i])s.pop();
            right[i]=s.empty()?n-i:s.top()-i;
            s.push(i);
        }
        for(int i=0;i<n;i++){
            maxSum=(maxSum+(1LL*arr[i]*left[i]*right[i]));
        }
        long long ans=0;
        ans=maxSum-minSum;
        return ans;   
    }
};