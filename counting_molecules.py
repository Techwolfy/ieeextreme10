c, h, o = input().split()
c = int(c)
h = int(h)
o = int(o)

'''
0x + y + 6z = c
2x + 0y + 12z = h
x + 2y + 6z = o
0 1 6
2 0 12
1 2 6

x 
|c 1 6|
|h 0 12|
|o 2 6|
-----
24
y
|0 c 6|
|2 h 12|
|1 o 6|
-----
24
z
|0 1 c|
|2 0 h|
|1 2 o|
-----
24
'''
x = (12*o+6*h-24*c)//24
y = (12*o-6*h)//24
z = (h+4*c-2*o)//24
x_remainder = (12*o+6*h-24*c)%24
y_remainder = (12*o-6*h)%24
z_remainder = (h+4*c-2*o)%24
if (x_remainder != 0 or y_remainder != 0 or z_remainder != 0):
    print("Error")
elif (x < 0 or y < 0 or z < 0):
    print("Error")
else:
    print('{} {} {}'.format(x,y,z))
