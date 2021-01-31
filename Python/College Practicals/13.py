# Importing and using Built-in packages

# Importing whole package
import random
print("Some random numbers in range 10 to 100")
for x in range(8):
    print(random.randint(15, 100), end=" ")
print()

# Importing specific function
from math import sqrt
num = int(input("Input a number: "))
print("Square root of ", num, "is", sqrt(num))



# Importing and using User defined packages



from helper import utility
birthYear = int(input("Your birth year: "))
print("Your age is ", utility.calculateAge(birthYear))

from helper.utility import sayHello
sayHello("Jonas")
