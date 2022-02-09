import random
from time import perf_counter
pi = 0
N = 100
for k in range(N): 
    pi += 1/pow(16,k)*( 4/(8*k+1) - 2/(8*k+4) - 1/(8*k+5) - 1/(8*k+6) )
# \ 是 换行标识符
print ("PI is {}".format(pi))

Total = 10000*10000
Hits = 0.0
start = perf_counter()
for i in range(1,Total+1):
    x,y=random.random(),random.random()
    dis = pow ((x**2+y**2),0.5)
    if(dis<=1.0):
        Hits+=1
dur = perf_counter() - start
pi = (Hits/Total) * 4
print("Pi is {} Use the time:{:.3f}s".format(pi,dur))
