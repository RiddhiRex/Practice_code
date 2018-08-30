# Complete the charityAllocation function below.
#Find the order in which the profits of a company are shared among the three charities A, B and C such that the charity with the lowest previous donations get the profit

def charityAllocation(profits):
    sumA=0
    sumB=0
    sumC=0
    result = []
    for each in profits:
        if(sumA == min(sumA, sumB, sumC)):
            sumA= sumA+each
            result.append('A')
        elif(sumB == min(sumA, sumB, sumC)):
            sumB= sumB+each
            result.append('B')
        else:
            sumC= sumC+each
            result.append('C')
    return result
