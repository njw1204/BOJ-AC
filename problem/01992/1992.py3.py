def solve(si,sj,le):
    global x
    cri=x[si][sj]
    fail=False
    for i in range(si,si+le):
        for j in range(sj,sj+le):
            if x[i][j]!=cri:
                fail=True
                break
        if fail: break
    if not fail: return cri
    else:
        return "(" + solve(si,sj,le//2) + solve(si,sj+le//2,le//2) + solve(si+le//2,sj,le//2) + solve(si+le//2,sj+le//2,le//2) + ")"

n=int(input())
x=[0]*(n+5)
for i in range(n):
    x[i]=input()
print(solve(0,0,n))