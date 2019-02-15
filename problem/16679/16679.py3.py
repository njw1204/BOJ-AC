for _ in range(int(input())):
	n,kk=map(int,input().split())
	mm=6**n
	orix=[*map(int,input().split())]
	x=sorted(orix)
	sumx=sum(x)
	dp=[[0]*(n*6+5) for _ in range(n+5)]
	dp[0][0]=6**n
	for i in range(1,7): dp[1][i]=6**n//6
	for i in range(2,n+1):
		for j in range(i,i*6+1):
			for k in range(1,7):
				s=j-k
				if s>0 and dp[i-1][s]: 
					dp[i][j]+=dp[i-1][s]//6
	mv,mi=0,0
	for i in range(n+1):
		o=kk-sum(x[i:])
		if o<=0:
			mv=6**n
			mi=i
		elif o>0 and sum(dp[i][o:])>mv:
			mv=sum(dp[i][o:])
			mi=i
	print(mv)
	dice=[0]*n
	for i in range(mi):
		for j in range(n):
			if orix[j]==x[i] and not dice[j]:
				dice[j]=1
				break
	print(' '.join(map(str,dice)))