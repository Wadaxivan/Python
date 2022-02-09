#CAlHalmet.py
def getText():
    txt = open(r"C:\Users\Future\Desktop\Python\Notes\Code\halmet.txt","r").read()
    txt = txt.lower()
    for ch in '!@#$%^&*+_,./:;<=>?"[\\]-{|}':
        txt = txt.replace(ch," ")
    return txt

hamletTxt = getText()
words = hamletTxt.split()
counts = {}
for word in words:
    counts[word] = counts.get(word,0)+1
items = list(counts.items())
items.sort(key=lambda x:x[1],reverse=True) #采用键值对中的第二个值进行排序,reverse=True表示按照从大到小的顺序进行输出
for i in range(10):
    word,count = items[i]
    print("{0:<10}{1:>5}".format(word,count))

