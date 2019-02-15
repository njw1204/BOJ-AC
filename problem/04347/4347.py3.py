from collections import deque

def hashing(field):
    val,weight=0,1
    for i in range(3):
        for j in range(3):
            if field[i][j]=="X": val+=weight*1
            elif field[i][j]=="O": val+=weight*2
            weight*=3
    return val

def unhash(hh):
    field=[[0]*3 for i in range(3)]
    for i in range(3):
        for j in range(3):
            if hh%3==0: field[i][j]="."
            elif hh%3==1: field[i][j]="X"
            else: field[i][j]="O"
            hh//=3
    return field

def turn(field):
    cnt1,cnt2=0,0
    for i in range(3):
        for j in range(3):
            if field[i][j]=="X": cnt1+=1
            elif field[i][j]=="O": cnt2+=1
    if cnt1>cnt2: return 1
    else: return 0

def gameend(field):
    for i in range(3):
        if field[i][0]==field[i][1]==field[i][2] and field[i][0]!=".":
            return True
        if field[0][i]==field[1][i]==field[2][i] and field[0][i]!=".":
            return True
    if field[0][0]==field[1][1]==field[2][2] and field[0][0]!=".":
        return True
    if field[0][2]==field[1][1]==field[2][0] and field[0][2]!=".":
        return True
    return False

asdf=["X","O"]
visit=[0]*100000
field=unhash(0)
visit[0]=1
q=deque()
q.append(0)
while q:
    field=unhash(q.popleft())
    order=turn(field)
    if gameend(field): continue
    for i in range(3):
        for j in range(3):
            if field[i][j]==".":
                field[i][j]=asdf[order]
                hh=hashing(field)
                if not visit[hh]:
                    visit[hh]=True
                    q.append(hh)
                field[i][j]="."

for t in range(int(input())):
    if t>0: input()
    field=[list(input()),list(input()),list(input())]
    if visit[hashing(field)]: print("yes")
    else: print("no")