from os import *
from sys import *
from collections import *
from math import *

def countDistinctElements(arr, k):
    # Write your code here
    n = len(arr)
    l = []
    for i in range(k,n+1):
        ans = len(list(set(arr[i-k:i])))
        l.append(ans)
    return l

    pass
