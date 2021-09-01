n=int(input())
namibia=0
kenya=0
tanzania=0
ethiopia=0
zim=0
zam=0
zimzam=0
zimzamMode=False
namaVisit=False
last=''
for i in range(n):
 go=input()
 if last==go: continue

 if go=='kenya': kenya=1
 if go=='tanzania': tanzania=1
 if go=='ethiopia': ethiopia=1
 if go=='zambia':
  if last=='zimbabwe':
   zim-=1
   zimzam+=1
  else: zam+=1
  last=go
  continue
 if go=='zimbabwe':
  if last=='zambia':
   zam-=1
   zimzam+=1
  else: zim+=1
  last=go
  continue
 zimzamMode=False
 if go=='south-africa' and namibia==0: namaVisit=True
 if go=='namibia': namibia=1

 last=go

ans=kenya*50+ethiopia*50+tanzania*50
if namaVisit: ans+=namibia*40
else: ans+=namibia*140
ans+=zim//2*45+zim%2*30
ans+=zam//2*80+zam%2*50
ans+=zimzam*50

if n%2==1: print(-1)
else: print(ans)