
#Find time of maximu overlap in intervals and find how many are overlapping at that max point of time.
#Given a list of intervals of guests arriving and leaving ie: start time and end time, find the time with maximum guests  


start=[13,30,29,14,40,17,3] 
end=[107,95,33,105,70,127,74]

def maxOverlap(start, end):
    n=len(start)
    maxe=max(end)
    x = [0]*(maxe+2)
    
    for i in range(n):
        x[start[i]]+=1
        x[end[i]+1]-=1
     
    maxcnt = -1   
    idx=-1
    curcnt=0
    for i in range(maxe+1):
        curcnt+=x[i]
        if(curcnt>maxcnt):
            maxcnt=curcnt
            idx=i
    return maxcnt, idx
    
print(maxOverlap(start, end))

    
