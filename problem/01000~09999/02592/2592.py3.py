N,max_cnt,most_num=[0]*101,0,0
average=0
for i in range(10):
 X=int(input())//10
 average+=X
 N[X]+=1
 if N[X]>max_cnt:
  max_cnt=N[X]
  most_num=X*10
print(average,most_num,sep='\n')