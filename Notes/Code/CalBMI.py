height,weight = eval(input("Please input the height(m) and the weight(kg):"))
BMI = weight/pow(height,2)
print("BMI is {:.2f}".format(BMI))
who,nat = "",""
if BMI<18.5:
    who,nat = ("Thin","Thin")
elif BMI>=18.5 and BMI<24:
    who,nat = ("Normal","Normal")
elif BMI>=24 and BMI<25:
    who,nat = ("Fat","Normal")
elif BMI>=25 and BMI<28:
    who,nat = ("Fat","Fat")
elif BMI>=28 and BMI<30:
    who,nat = ("Too Fat","Fat")
else:
    who,nat = ("Too Fat","Too Fat")
print("WHO:{} , National:{}".format(who,nat))
