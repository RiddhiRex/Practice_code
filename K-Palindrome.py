
#Check if a string is a palindrome or not after deleting atmost k characters.
def kpalin(st, rev, l1, l2):
    if not l1:
        return l2
    if not l2:
        return l1
    if(st[l1-1]==rev[l2-1]):
        return kpalin(st, rev, l1-1, l2-1)
        
    res = 1+min(kpalin(st, rev, l1-1, l2), 
                (kpalin(st, rev, l1, l2-1)))
    return res

st="riddhhir"
k=2    
revst=st[::-1]
l=len(st)
ans = kpalin(st, revst, l, l)
print(ans)
if ans<=k *2:
    print(True)
else:
    print(False)
