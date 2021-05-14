import sys
sys.setrecursionlimit(10001)
class Node:
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None
        self.parent = None

def addNode(value):
    global root
    current_node = root
    done = False
    while(not done):
        if(value < current_node.value):
            if(current_node.left is None):
                current_node.left = Node(value)
                done = True
            else:
                current_node = current_node.left    
        else:
            if(current_node.right is None):
                current_node.right = Node(value)
                done = True
            else:
                current_node = current_node.right
def bfs(node):
    if(node is None):
        return
    bfs(node.left)
    bfs(node.right)
    print(node.value)

def one(left,right):
    if(left > right):
        return
    root = tree[left]
    idx = right
    while root < tree[idx]:
        idx = idx-1
    one(left+1,idx)
    one(idx+1,right)
    print(root)

#i = int(input())
#root = Node(i)
#real_root = root
#current = root
tree = []
while True:
    try:
        i = int(input())
        #current = addNode(i)
        tree.append(i)
    except:break
#bfs(real_root)
one(0,len(tree)-1)