import turtle
def Koch(size,n):
    if n==0:
        turtle.fd(size)
    else:
        for angle in [0,60,-120,60]:
            turtle.left(angle)
            Koch(size/3,n-1)
def main():
    turtle.setup(600,600)
    turtle.penup()
    turtle.goto(-250,200)
    turtle.pendown()
    turtle.pensize(2)
    turtle.colormode(255)
    turtle.pencolor(135,206,235)
    level=5
    Koch(600,level)
    turtle.right(120)
    Koch(600,level)
    turtle.right(120)
    Koch(600,level)
    turtle.hideturtle()
    turtle.done()
main()