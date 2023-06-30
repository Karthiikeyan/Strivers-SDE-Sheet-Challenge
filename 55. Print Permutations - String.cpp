from os import *
from sys import *
from collections import *
from math import *

def subparts(n, string, s, freq, ans):
	if len(string)==n:
		ans.append(string)
		return

	for i in range(n):
		if not freq[i]:
			freq[i] = True
			subparts(n, string+s[i], s, freq, ans)
			freq[i] = False
			
	
def findPermutations(s):
	# Write your code here.
	n = len(s)
	ans = []
	freq = [False]*n
	subparts(n,"", s, freq, ans)
	return ans
	pass