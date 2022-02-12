import turtle as t
t.setup(650,350,200,200)
t.penup() # change the position
t.fd(-250) # go straight 
t.pendown()
t.pensize(25)
t.pencolor("pink") # Or use the RGB number (float version) purple:(0.5,0,0.5)
t.seth(-40) # change the angle
#t.left change the relative angle
for i in range(4):
    t.circle(40,80) # draw a circle,the positive number is left and the negative number is right,the scecond number is the angle
    t.circle(-40,80)
t.circle(40,80/2)
t.fd(40)
t.circle(16,180)
t.fd(40*2/3)
t.done()
