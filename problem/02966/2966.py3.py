s="ABC"*50
c="BABC"*50
h="CCAABB"*50

n=int(input())
x=input()
ac,bc,cc=0,0,0

for i in range(n):
    if s[i]==x[i]: ac+=1
    if c[i]==x[i]: bc+=1
    if h[i]==x[i]: cc+=1

mc=max(ac,bc,cc)
print(mc)
if ac==mc: print("Adrian")
if bc==mc: print("Bruno")
if cc==mc: print("Goran")