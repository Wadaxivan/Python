from dataclasses import dataclass
import turtle as t
t.title("AutoTraceDraw")
t.setup(800,600,0,0)
t.pencolor("red")
t.pensize(5)
datals = []
f = open("c:/Users/Future/Desktop/Python/Notes/Code/data.txt")
for line in f:
    line = line.replace("\n","")
    datals.append(list(map(eval,line.split(",")))) #map能把第一个函数执行于每个参数
f.close()
print(datals)
for i in range(len(datals)):
    t.pencolor(datals[i][3],datals[i][4],datals[i][5])
    t.fd(datals[i][0])
    if datals[i][1]:
        t.right(datals[i][2])
    else:
        t.left(datals[i][2])
t.done()
         
       