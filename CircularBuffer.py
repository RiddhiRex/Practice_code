class CircularBuffer:
    def __init__(self):
        self.buffer = []
        self.capacity = 4
    
    def write(self, val):
        if len(self.buffer)<self.capacity:
            self.buffer.append(val)
        else:
            self.buffer.pop(0)
            self.buffer.append(val)
    
    def read(self):
        if len(self.buffer)>0:
            return self.buffer.pop(0)
        else:
            return None
    def showContents(self):
        return self.buffer
        
obj = CircularBuffer()
obj.write(1)
obj.write(2)
obj.write(3)
obj.write(4)
obj.write(5)
obj.write(6)
print(obj.showContents())
print(obj.read())
print(obj.read())
print(obj.showContents())
