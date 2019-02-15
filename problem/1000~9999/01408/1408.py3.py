from datetime import *
T=lambda x:datetime.strptime(input(),"%H:%M:%S")
A,B=T(0),T(1)
if A>B:B+=timedelta(1)
H,M,S=map(int,str(B-A).split(':'))
print('%02d:%02d:%02d'%(H,M,S))