def searchMatrix(mat: [[int]], target: int) -> bool:
    # Write your code here.
    l = []
    for i in mat:
        l += i
    
    if target in l: 
        return True
    else: 
        return False
    pass
