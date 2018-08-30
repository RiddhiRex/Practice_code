#To find the max difference between the higher indexed even integer and the lower indexed odd integer in a list.

def maxDifferenceOddEven(a):
    if len(a) < 1:
        return -1
    minodd=float("inf")
    maxdif = -float("inf")
    for i in range(len(a)):
        if(a[i]%2!=0):
            minodd = min(minodd, a[i])
        else:
            if minodd!=-float("inf"):
                maxdif= max(maxdif, a[i]-minodd)
    if maxdif==-float("inf"):
        return -1
    else:
        return maxdif
