import random
def main():
    printIntro()
    proA,proB,N = getInputs()
    CalNGame(proA,proB,N)

def printIntro():
    print("Welcome to use the system,please input the \
ability of A and B and the number of matches. \
We can give you the probability of winning.")

def getInputs():
    a = eval(input("Please input the ability of A(0-1):"))
    b = eval(input("Please input the ability of B(0-1):"))
    n = eval(input("Please input the number of matches:"))
    return a,b,n

def CalNGame(a,b,n):
    winA,winB = 0,0
    for i in range(n):
        if CalOneGame(a,b):
            winA+=1
        else:
            winB+=1
    print("The probability of winning is following:")
    print("A:Winner:{},Probability:{:0.1%}".format(winA,winA/n)) 
    print("B:Winner:{},Probability:{:0.1%}".format(winB,winB/n))

def CalOneGame(a,b):
    winA,winB = 0,0
    start = "A"
    while winA!=15 and winB!=15:
        goal = random.random()
        if start == "A":
            if goal < a:
                winA+=1
            else:
                start = "B"
        else:
            if goal < b:
                winB+=1
            else:
                start = "A"
    if winA == 15:
        return True
    else:
        return False
main()