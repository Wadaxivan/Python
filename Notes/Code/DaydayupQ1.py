#DaydayupQ1.py
dayup = pow(1.001,365)
daydown = pow(0.999,365)

dayup2 = 1
daydown2 = 1
for i in range(365):
    dayup2 = dayup2 + dayup2 * 0.001
    daydown2 = daydown2 - daydown2 * 0.001

print("UP：{:.2f} DOWN：{:.2f}".format(dayup,daydown))
print("UP：{:.2f} DOWN：{:.2f}".format(dayup2,daydown2))
