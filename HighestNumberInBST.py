
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

    def highestNumberInBST(self, root):
        if root is None:
            return
        while(root.right is  not None):
            root=root.right
        return root.val
            
        
obj = solution()
root=None
root = obj.insert(root, 4)
root = obj.insert(root, 2)
root = obj.insert(root, 5)

print(obj.highestNumberInBST(root))
