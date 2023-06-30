from math import *
from collections import *
from sys import *
from os import *

def missingAndRepeating(arr, n):
    ans = (n*(n+1))//2
    tot = sum(list(set(arr)))
    miss = ans-tot
    total_ans = sum(arr)+miss
    rep = total_ans-ans
    return [miss, rep]
    # Write your code here
    pass
