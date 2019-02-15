# 폴더명을 규격에 맞게 일괄 변경 (빈 공간을 0으로 채운 5자리 정수)

import os
for i in os.listdir():
 if not os.path.isdir(i): continue
 n = "%05d" % int(i)
 os.rename(i, n)