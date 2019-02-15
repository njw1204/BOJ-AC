def G(a,b): return G(b,a%b) if b else a
def L(a,b): return a*b//G(a,b) 
for i in range(int(input())): print(L(*map(int,input().split())))