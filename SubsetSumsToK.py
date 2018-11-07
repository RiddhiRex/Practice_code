#Find subsets of given array which sums to k

n = [1,3,2,6,4,5]
sum=6
ans = []
def subsetSum(nos, sum, cursum, curset):
    if cursum==sum:
        ans.append(curset)
    if(len(nos)==0):
        return
    
    if cursum>sum:
        return
    for i, no in enumerate(nos):
        remaining_nos = nos[i+1:]
        subsetSum(remaining_nos, sum, cursum+no, curset+[no])
     
    return

subsetSum(n, sum, 0, [])
print(ans)
