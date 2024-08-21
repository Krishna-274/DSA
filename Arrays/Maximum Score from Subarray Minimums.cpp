//From the subarray arr[i...j], select the smallest and second smallest numbers and add them, you will get the score for that subarray. Return the maximum possible score across all the subarrays of array arr[].


//Brute force
int pairWithMaxSum(vector<int> &arr) {
      int n=arr.size();
      int maxi = 0;
        for(int i=0;i<n-1;i++){
            int smallest = arr[i];
            int secSmallest = INT_MAX;
            for(int j=i+1;j<n;j++){
                if(arr[j]<=smallest){
                    secSmallest = smallest;
                    smallest = arr[j];
                }
                else{
                    secSmallest = min(secSmallest, arr[j]);
                }
                maxi = max(maxi, smallest+secSmallest);
            }
            //cout<<i<<" "<<smallest<<" "<<secSmallest<<" "<<endl;
        }
        return maxi;


///Optimal

        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans = max(arr[i]+arr[i+1], ans);
        }
        return ans;
