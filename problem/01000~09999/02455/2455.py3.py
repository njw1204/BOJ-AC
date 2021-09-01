people,max=0,0
for i in range(4):
 out,come=map(int,input().split())
 people+=come-out
 if people>max: max=people
print(max)