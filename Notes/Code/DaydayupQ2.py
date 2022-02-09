#DaydayupQ2.py
def dayUP(factor):
    dayup = 1
    for i in range(365):
        if i%3 in [0,7]:
            dayup = dayup * (1-0.01)
            #daydown = daydown * (1-factor)
        else:
            dayup = dayup * (1+factor)
            #daydown 
    return dayup
dayfactor = 0.01
dayupst = pow(1.01,365)
while dayUP(dayfactor) < dayupst:
    dayfactor += 0.001
print("向上：{:.2f} 程度：{:.3f}".format(dayUP(dayfactor),dayfactor))
#print("向上：{:.2f} 向下：{:.2f}".format(dayup2,daydown2))
