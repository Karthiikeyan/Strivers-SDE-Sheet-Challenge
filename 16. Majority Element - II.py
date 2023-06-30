from math import *
from collections import *
from sys import *
from os import *

def majorityElementII(arr):
	# Write your code here.
	l = []
	n = len(arr)//3
	lst = list(set(arr))
	for i in lst:
		if arr.count(i) > n:
			l.append(i)
	
	return l
	pass