class TrieNode:
    def __init__(self):
        
        self.child = [None]*26
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = self.getNode()
    
    def getNode(self):
        return TrieNode()
    
    def getKey(self,ch):
        return ord(ch) - ord('a')
    
    def insert(self,word):
        
        level = self.root 
        for i in range(len(word)):
            
            key = self.getKey(word[i])
            if level.child[key] == None:
                level.child[key] = self.getNode()
            level = level.child[key]
            
        level.isEnd = True
        
    
    def search(self,word):
        
        level = self.root
        for i in range(len(word)):
            
            key = self.getKey(word[i])
            if level.child[key] == None:
                return False
            else:
                level = level.child[key]
        
        return level.isEnd
                

if __name__ == "__main__":
    
    t = Trie()
    t.insert("test");t.insert("testing");t.insert("ram")
    print t.search("testing")
