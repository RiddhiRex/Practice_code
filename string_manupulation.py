import collections
import operator
s= "i food am cat bat rat she he was in home india who where to find the college of cat on home with books apple frog wear"
st = s.split(" ")
#most frequently occuring word
#d = collections.Counter(st)
#print(sorted(sorted(d.items()), key=operator.itemgetter(1), reverse=True)[0])

#word with max vowels
maxcnt=0
maxword=""
for each in st:
    cnt=each.count('a')+each.count('e')+each.count('i')+each.count('o')+each.count('u')
    if cnt>maxcnt:
        maxcnt=cnt
        maxword = each
    elif cnt==maxcnt:
        if sorted([maxword, each])[0]==each:
            maxword=each
print(maxword, maxcnt)

dic={}
#word with median length of all words occuring in sentence
for each in st:
    dic[each]=len(each)
    
print(sorted(sorted(dic.items()), key=operator.itemgetter(1))[len(dic)//2])

