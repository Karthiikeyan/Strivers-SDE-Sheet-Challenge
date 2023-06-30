def findCelebrity(n, knows):
    i=0
    j=n-1
    while i<j:
        if knows(i,j):
            i+=1
        else:
            j-=1

    ## i is my answer revalidate my answer
    for c in range(n):
        if c!=i and (knows(c,i)==False or knows(i,c)):
            return -1
    return i