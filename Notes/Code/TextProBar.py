'''import time
scale = 10
print("--------start--------")
for i in range(scale+1):
    a = "*" * i
    b = "•" * (scale-i)
    ratio = i/scale*100
    print("\r{:^3.0f}%[{}->{}]".format(ratio,a,b),end=" ")
    time.sleep(0.1)
print("\r")
print("--------end--------")'''
from cmath import pi
import time
import math
scale = 50
print("start".center(scale+15,"-")) #居中处理
start = time.perf_counter()
for i in range(scale+1):
    a = "*" * i
    b = "•" * (scale-i)
    x = (i/scale)*100
    ratio = x + (1 - math.sin(x*pi*2+pi/2))/-8
    dur = time.perf_counter() - start
    print("\r{:^3.0f}%[{}->{}]{:.2f}s".format(ratio,a,b,dur),end=" ")
    time.sleep(0.1)
print("\n"+"end".center(scale+15,"-"))