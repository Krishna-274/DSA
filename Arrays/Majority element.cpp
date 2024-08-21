//Brute force
   int majorityElement(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
       int cnt=0;
             for(int j=0;j<n;j++)
             {
                if(nums[j]==nums[i])
                cnt++;
             }
      if(cnt>n/2)
      return nums[i];
       } 
   
    return -1;
   }



//Better approach
int majorityElement(vector<int>& nums) {
        int n=nums.size();
       map<int ,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
        if(it.second>n/2)
        return it.first;
    }
    return -1;}





//Optimal approach--MOORE'S VOTING ALGORITHM
int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
   //this loop not required if prblm states that there definitely exists a majority element
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}
