#-*- coding=UTF-8 -*-
fo = open("output.txt","w+")
ls = ["中国","就是牛"]
fo.writelines(ls)
fo.seek(0)
for line in fo:
    print(line)
fo.close()