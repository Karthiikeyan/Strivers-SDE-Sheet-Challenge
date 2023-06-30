from os import *
from sys import *
from collections import *
from math import *

def compareVersions(a, b):
    #Write your code here
    a = a.split('.')
    b = b.split('.')
    maxi = max(len(a), len(b))
    for i in range(maxi):
        n = int(a[i]) if i<len(a) else 0
        m = int(b[i]) if i<len(b) else 0
        if n > m:
            return '1'
        elif n < m:
            return '-1'
    return '0'