#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long long left = 0;
    long long right = n-1;
    long long left_max = 0;
    long long right_max = 0;
    long long ans = 0;

    while(left<=right){
        if(arr[left]<=arr[right]){
            if(arr[left]>=left_max) left_max = arr[left];
            else
                ans += left_max - arr[left];
            left++;
        }
        else{
            if(arr[right]>=right_max) right_max = arr[right];
            else
                ans += right_max - arr[right];
            right--;
        }
    }
    return ans;
}