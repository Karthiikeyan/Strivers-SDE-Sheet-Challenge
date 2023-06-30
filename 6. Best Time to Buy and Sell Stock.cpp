#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int profit = 0;
    int n = prices.size();
    int mini = prices[0];
    for(int i=1;i<n;i++){
        int sum = prices[i] - mini;
        profit = max(profit, sum);
        mini = (mini>prices[i]) ? prices[i] : mini;
    }

    return profit;
}