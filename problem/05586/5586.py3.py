import re
a=input()
print(len(re.findall('(?=JOI)',a)))
print(len(re.findall('(?=IOI)',a)))