string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    int i = 0;
    while(true){
        char letter = arr[0][i];
        for(int j=1;j<n;j++){
            if(i>=arr[j].size() || arr[j][i]!=letter){
                return ans;
            }
        }
        ans += letter;
        i++;
    }
    return ans;
}


