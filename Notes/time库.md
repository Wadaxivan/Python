# Time库
---
### 三种时间格式
![](image/2022-02-02-22-00-54.png)
![](image/2022-02-02-22-01-48.png)
```python{class=line-numbers cmd=true}
import time
print(time.time())
print(time.ctime())
print(time.gmtime())
```
### 时间格式化
![](image/2022-02-02-22-04-16.png)
![](image/2022-02-02-22-08-40.png)
![](image/2022-02-02-22-05-36.png)
![](image/2022-02-02-22-06-17.png)

```python{class=line-numbers cmd=true}
import time
t = time.gmtime()
print(time.strftime("%Y-%m-%d %A %H:%M:%S",t))
```

### 程序计时
![](image/2022-02-02-22-12-26.png)
```python{class=line-numbers cmd=true}
import time
start = time.perf_counter()
end = time.perf_counter()
print((end-start)*10e6)
```
