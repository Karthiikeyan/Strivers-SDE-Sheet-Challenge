def writeAsYouSpeak(n):
    # Write your code here.
    ans = "1"
    for i in range(1,n):
        cnt = 1
        string = ""
        for j in range(len(ans)):
            if j+1<len(ans) and ans[j]==ans[j+1]:
                cnt += 1
            else:
                string += str(cnt)+ans[j]
                cnt = 1
        ans = string
    return ans