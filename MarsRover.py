
import numpy

matrix=[i for i in range(matrixSize*matrixSize)]
mat = numpy.array(matrix).reshape(matrixSize, matrixSize)
i=0
j=0
while(len(cmds)>0):
    curcmd=cmds.pop(0)
    if curcmd=='LEFT' and j>0:
       j-=1
    elif curcmd=='RIGHT' and j<matrixSize-1:
        j+=1
    elif curcmd=='UP' and i>0:
        i-=1
    elif curcmd=='DOWN' and i<matrixSize-1:
        i+=1
print(mat[i][j])
