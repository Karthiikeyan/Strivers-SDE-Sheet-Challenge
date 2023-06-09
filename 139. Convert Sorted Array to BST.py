from os import *
from sys import *
from collections import *
from math import *

'''
    Following is the TreeNode class structure
'''
class TreeNode :
	def __init__(self, val) :
		self.val = val
		self.left = None
		self.right = None

	def __del__(self):
		if self.left:
			del self.left
		if self.right:
			del self.right
            


def sortedArrToBST(arr, n):
    
    # Write your code here
	def helper(l, r):
		if l > r:
			return None
		mid = (l+r)//2
		root = TreeNode(arr[mid])
		root.left = helper(l, mid-1)
		root.right = helper(mid+1, r)
		return root

	return helper(0, len(arr)-1)
    