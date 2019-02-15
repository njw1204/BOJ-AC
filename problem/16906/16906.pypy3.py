class Node:
    def __init__(self,id,parent,val):
        self.id=id
        self.parent=parent
        self.ch1,self.ch2=0,0
        self.val=val
        self.leaf=True

n=int(input())
orix=[*map(int,input().split())]
x=sorted(orix)
node=dict()
node[1]=Node(1,0,-1)
cnt=1
li=[]

for i in x:
    li2=[]
    root=node[1]
    for j in range(i):
        if root.ch1==0:
            cnt+=1
            node[cnt]=Node(cnt,root.id,0)
            root.ch1=cnt
            root.leaf=False
            root=node[cnt]
            li2.append("0")
        elif root.ch2==0:
            cnt+=1
            node[cnt]=Node(cnt,root.id,1)
            root.ch2=cnt
            if j==i-1:
                while root.id!=1:
                    if node[root.ch1].leaf and node[root.ch2].leaf:
                        root.leaf=True
                        root=node[root.parent]
                    else: break
            else: root=node[cnt]
            li2.append("1")
        elif not node[root.ch1].leaf:
            root=node[root.ch1]
            li2.append("0")
        elif not node[root.ch2].leaf:
            root=node[root.ch2]
            li2.append("1")
        else:
            print(-1)
            exit(0)
    li.append("".join(li2))

print(1)
for i in li:
    for j in range(n):
        if orix[j]==len(i):
            break
    orix[j]=i
for i in orix: print(i)