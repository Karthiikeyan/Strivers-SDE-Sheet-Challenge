def isItSudoku(matrix):

    # Write your codehere.
    for i in range(9):
        for j in range(9):
            if matrix[i][j] == 0:
                for k in range(1, 10):
                    if valid(i, j, k, matrix):
                        matrix[i][j] = k
                        if isItSudoku(matrix):
                            return True
                        else:
                            matrix[i][j] = 0
                return False
    return True
 
def valid(row, col, k, matrix):
    for l in range(9):
        if matrix[l][col] == k:
            return False
        if matrix[row][l] == k:
            return False
        if matrix[3*(row//3)+l//3][3*(col//3)+l%3] == k:
            return False
    return True
    pass

