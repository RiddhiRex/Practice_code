
class TreeNode(object):
    def __init__(self, val):
        self.val=val
        self.left=None
        self.right=None
        
class solution:
    def insert(self, root, val):
        if root is None:
            return TreeNode(val)
        if(root.val>val):
            root.left = self.insert(root.left, val)
        else:
            root.right = self.insert(root.right, val)
        return root  

    
    def NthLargestNo(self, root, n):
        if root==None:
            return
        
        self.NthLargestNo(root.right, n)
        self.cnt+=1
        if(self.cnt==n):
            print(root.val)
        self.NthLargestNo(root.left, n)
        return
        
obj = solution()
root=None
root = obj.insert(root, 4)
root = obj.insert(root, 2)
root = obj.insert(root, 5)
root = obj.insert(root, 1)
root = obj.insert(root, 6)
obj.cnt=0
obj.NthLargestNo(root, 4)
