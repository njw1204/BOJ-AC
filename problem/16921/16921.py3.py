n=int(input());_=0,;exec("_=set([j+k for j in _ for k in[1,5,10,50]]);"*min(n,12));print(len(_)+max(0,(n-12)*49))