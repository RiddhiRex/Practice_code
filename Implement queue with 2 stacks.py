#given 2 stacks, implement a queue 
class queue:
    def __init__(self):
        self.stack1=[]
        self.stack2=[]

    def enqueue(self, val):
        self.stack1.append(val)

    def dequeue(self):
        if(len(self.stack1)==0):
            return None
        while(len(self.stack1)>1):
            self.stack2.append(self.stack1.pop())
        if(len(self.stack1)==1):
            val = self.stack1.pop()
            
        while(len(self.stack2)>0):
            self.stack1.append(self.stack2.pop())
        return val
            
self = queue()
self.enqueue(4)
self.enqueue(5)
self.enqueue(6)
print(self.dequeue())
print(self.dequeue()) 
print(self.dequeue())
print(self.dequeue())
self.enqueue(5)
self.enqueue(6)
print(self.dequeue())

#method 2 (efficient)
#give 2 stacks, implement a queue 
class queue:
    def __init__(self):
        self.stack1=[] #for enqueue
        self.stack2=[] #for dequeue

    def enqueue(self, val):
        self.stack1.append(val)

    def dequeue(self):
        if not self.stack2:
            if(len(self.stack1)==0):
                return None
            while(len(self.stack1)>0):
                self.stack2.append(self.stack1.pop())
        val = self.stack2.pop()
        return val
            
self = queue()
self.enqueue(4)
self.enqueue(5)
self.enqueue(6)
print(self.dequeue())
print(self.dequeue()) 
print(self.dequeue())
print(self.dequeue())
self.enqueue(5)
self.enqueue(6)
print(self.dequeue())
        
    
