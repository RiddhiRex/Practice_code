#In a stream of bits as input (one byte at a time), write a C program to find 5 contiguous 1's.
b = '101111100011011111011010100'
maxone=0

i=0
cnt=0
while(i<len(b)):
    cnt=0
    while(i<len(b) and b[i]=='1'):
        i+=1
        cnt+=1
    if cnt>=5:
        print(i-5) #printing the index of starting of 5 consecutive ones.
    i+=1

        
