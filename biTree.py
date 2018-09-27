class tree:
    def __init__(self,root=None):
        self.root=root


def printTree(node):
        if(node):
            print(node.key)
            printTree(node.l)
            printTree(node.r)
            

class node:
    def __init__(self,value=None,lChild=None,rChild=None):
        self.key=value
        self.l=lChild
        self.r=rChild



def constructTree(anode,preOder,midOrder):
    print preOder
    print midOrder
    if(preOder):
        anode.key=preOder[0]
        print preOder[0]
        index=midOrder.index(preOder[0])
        if(index==0):
            anode.l=None
        else:
            anode.l=node()
            anode.l=constructTree(anode.l,preOder[1:index+1],midOrder[0:index]) 
        anode.r=node()
        anode.r=constructTree(anode.r,preOder[index+1:len(midOrder)],midOrder[index+1:len(midOrder)])
        return anode
    else:
        return None


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        if(pre):
            myNode=TreeNode(pre[0])
            index=tin.index(pre[0])
            if(index==0):
                myNode.left=None
            else:
                myNode.left=self.reConstructBinaryTree(pre[1:index+1],tin[0:index]) 
            myNode.right=self.reConstructBinaryTree(pre[index+1:len(tin)],tin[index+1:len(tin)])
            return myNode
        else:
            return None



preOder=[1,2,4,7,3,5,6,8]
midOrder=[4,7,2,1,5,3,8,6]
myTree=tree()
myTree.root=node()
myTree.root=constructTree(myTree.root,preOder,midOrder)
printTree(myTree.root)
