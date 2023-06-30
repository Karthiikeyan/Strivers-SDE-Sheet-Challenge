#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && arr[j]==arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum < target) k++;
                else if(sum > target) l--;
                else{
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
