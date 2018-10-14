#Convert ternary expression into binary tree from geeks for geeks
class TreeNode(object):
    def __init__(self, val):
        self.val=val
        self.left=None
        self.right=None
    
class solution(object):
    def traverse(self, exp):
        if len(exp)==0:
            return None
        root=TreeNode(exp[0])
        stack=[]
        stack.append(root)
        
        for i in range(1, len(exp), 2):
            op = exp[i]
            no=exp[i+1]
            if op=="?":
                l=TreeNode(no)
                stack[-1].left=l
                stack.append(l)
                
            elif op==":":
                r=TreeNode(no)
                stack.pop()
                if stack[-1].right!=None:
                    stack.pop()
                stack[-1].right=r
                stack.append(r)

        return root
        
    def print_inorder(self, node):
        if node is None:
            return

        self.print_inorder(node.left)
        print(node.val)
        self.print_inorder(node.right)
        return

self=solution()
exp="a?b?c:d:e"
root = self.traverse(exp)
self.print_inorder(root)
