#From geeks for geeks
import itertools
n=10
m=11
n=bin(n)[2:]
m=bin(m)[2:]
n=str(n)
m=str(m)
l=len(str(n))
ans = []
while(l>0):
    no = set(itertools.combinations(n,l))
    no=list(no)
    for i in range(len(no)):
        no[i]="".join(no[i])
    ans =[(i) for i in no if i in m]
    if(len(ans)>0): 
        print(int(ans[0], 2))
        break
    else:
        l-=1
        
