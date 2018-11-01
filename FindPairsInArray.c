#Given an integer array, find pair of numbers such that X &gt; Y and X occurs earlier than Y in the array. 
def findPair(no):
    maxsofar=float("-inf")
    for each in no:
        if each>maxsofar:
            maxsofar=each
        elif each<maxsofar:
            return([maxsofar, each])
    return []
    
ret = findPair([2,3,4,5,1])
if len(ret)==0:
    print("No such pairs")
else:
    print(ret)
        
