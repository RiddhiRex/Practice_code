
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

    def levelOrderTraversal(self, root):
        if root is None:
            return []
        curr=[root]
        ans = []
        next_level=[]
        cur_val = []
        while len(curr)>0:
            for each in curr:
                cur_val.append(each.val)
                if each.left is not None:
                    next_level.append(each.left)
                if each.right is not None:
                    next_level.append(each.right)
            curr=next_level
            next_level=[]
            ans.append(cur_val)
            cur_val = []
        return ans
                
        
obj = solution()
root=None
root = obj.insert(root, 4)
root = obj.insert(root, 2)
root = obj.insert(root, 5)

print(obj.levelOrderTraversal(root))
