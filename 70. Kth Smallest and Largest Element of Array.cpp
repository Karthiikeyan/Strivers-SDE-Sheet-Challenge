def kthSmallLarge(arr, n, k):
    # Write your code here
    return sorted(arr)[k-1],sorted(arr)[-k]
    pass
