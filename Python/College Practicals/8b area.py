def areaOfCircle(radius):
    return radius*radius

def areaOfSquare(side):
    return side*side

def areaOfRectangle(length, breadth):
    return length*breadth

def areaOfTriangle(base, height):
    return 0.5 * base * height

print("Welcome to Area calculator !!")

while(True):
    print("Choose type of figure to find the area of: ")
    print("1. Square            2. Rectangle            3. Circle           4. Triangle         5. Exit")

    choice =  float(input())
    if choice == 1:
        side =  float(input("Enter side of square(in cm): "))
        print(areaOfSquare(side))
    elif choice == 2:
        len =  float(input("Enter length of rectangle(in cm): "))
        breadth =  float(input("Enter breadth of rectangle(in cm): "))
        print(areaOfRectangle(len, breadth))
    elif choice == 3:
        radius =  float(input("Enter radius of circle(in cm): "))
        print(areaOfCircle(radius))
    elif choice == 4:
        base =  float(input("Enter base of triangle(in cm): "))
        height =  float(input("Enter height of triangle(in cm): "))
        print("Area: ", areaOfTriangle(base, height))
    elif choice == 5:
        print("Bye, Have a nice day !!")
        break
    else:
        print("Invalid choice, try again")


