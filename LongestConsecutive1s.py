#Length of the Longest Consecutive 1s in Binary Representation of list of numbers

n = [15,1,2,10]
maxone=0
for each in n:
    b = bin(each)[2:]
    i=0
    cnt=0
    while(i<len(b)):
        if b[i]=='1':
            cnt+=1
            maxone=max(maxone, cnt)
        else:
            cnt=0
        i+=1
print(maxone)
        
