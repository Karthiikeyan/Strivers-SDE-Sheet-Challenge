#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[9] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans = 0;
    int i=0;
    while(amount && i<=8){
        if(amount<coins[i]){
            i++;
            continue;
        }
        ans++;
        amount -= coins[i];
    }
    return ans;

}
