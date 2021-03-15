l=int(input('enter length of rectangle : '))
b=int(input('enter breadth of a rectangle : '))
s=int(input('enter side of a square : '))
r=int(input('enter radius of a circle : '))
h1=int(input('enter base of a triangle : '))
h2=int(input('enter height of a triangle : '))

def AreaOfRectangle(l,b):
    return l*b

def AreaOfSquare(s):
    return s*s

def AreaOfCircle(r):
    return 3.14*r*r

def AreaOfTriangle(h1,h2):
    return ((1/2)*h1*h2)

print('area of rectangle is ',AreaOfRectangle(l,b),'sq.unit')
print('area of square is ',AreaOfSquare(s),'sq.unit')
print('area of circle is ',AreaOfCircle(r),'sq.unit')
print('area of triangles is ',AreaOfTriangle(h1,h2),'sq.unit')
