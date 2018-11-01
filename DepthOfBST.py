
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
        
    def depthofBst(self, root):
        if root is None:
            return 0
        if root.left is None:
            return self.depthofBst(root.right)+1
        elif root.right is None:
            return self.depthofBst(root.left)+1
        else:
            return max(self.depthofBst(root.left), self.depthofBst(root.right))+1

obj = solution()
root=None
root = obj.insert(root, 4)
root = obj.insert(root, 2)
root = obj.insert(root, 5)
print(obj.depthofBst(root))
